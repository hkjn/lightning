#include "serial.h"
#include <unistd.h>
#include "yajl/src/api/yajl_tree.h"
#include "flags.h"

#define COMMANDER_REPORT_SIZE       3584
#define COMMANDER_NUM_SIG_MIN       14// Must be >= desktop app's `MAX_INPUTS_PER_SIGN` !!
#define COMMANDER_SIG_LEN           154// sig + recid + json formatting
#define COMMANDER_ARRAY_MAX         (COMMANDER_REPORT_SIZE - (COMMANDER_SIG_LEN * 8))// Multiple is emperically found such that NUM_SIG_MIN is maximum
#define COMMANDER_ARRAY_ELEMENT_MAX 1024
#define ERR_IO_REPORT_BUF 107

static int REPORT_BUF_OVERFLOW = 0;
__extension__ static char json_array[] = {[0 ... COMMANDER_ARRAY_MAX] = 0};
__extension__ static char json_report[] = {[0 ... COMMANDER_REPORT_SIZE] = 0};

void commander_clear_report(void)
{
    memset(json_report, 0, COMMANDER_REPORT_SIZE);
    REPORT_BUF_OVERFLOW = 0;
}

const char *commander_read_report(void)
{
    return json_report;
}


void commander_fill_report(const char *cmd, const char *msg, int flag)
{
    char *p = json_report;

    if (!strlens(json_report)) {
        strncat(json_report, "{", 1);
    } else {
        json_report[strlens(json_report) - 1] = ','; // replace closing '}' with continuing ','
    }

    if (strlens(msg)) {
        snprintf(p + strlens(json_report), COMMANDER_REPORT_SIZE - strlens(json_report),
                 "\"%s\":{\"message\":\"%s\",\"code\":%s,\"command\":\"%s\"}",
                 attr_str(ATTR_error), msg, flag_code(flag), cmd);
    } else {
        snprintf(p + strlens(json_report), COMMANDER_REPORT_SIZE - strlens(json_report),
                 "\"%s\":{\"message\":\"%s\",\"code\":%s,\"command\":\"%s\"}",
                 attr_str(ATTR_error), flag_msg(flag), flag_code(flag), cmd);
    }
    //else if (flag == DBB_JSON_BOOL || flag == DBB_JSON_ARRAY || flag == DBB_JSON_NUMBER) {
    //    snprintf(p + strlens(json_report), COMMANDER_REPORT_SIZE - strlens(json_report),
    //             "\"%s\":%s", cmd, msg);
    //} else {
    //    snprintf(p + strlens(json_report), COMMANDER_REPORT_SIZE - strlens(json_report),
    //             "\"%s\":\"%s\"", cmd, msg);
    //}

    if ((strlens(json_report) + 1) >= COMMANDER_REPORT_SIZE) {
        commander_clear_report();
        snprintf(json_report, COMMANDER_REPORT_SIZE,
                 "{\"%s\":{\"message\":\"%s\",\"code\":%s,\"command\":\"%s\"}}", attr_str(ATTR_error),
                 flag_msg(ERR_IO_REPORT_BUF), flag_code(ERR_IO_REPORT_BUF), cmd);
        REPORT_BUF_OVERFLOW = 1;
    } else {
        strcat(json_report, "}");
    }
}


int main(int argc, char* argv[])
{
    //Wait for the hardware to be plugged in
    do {
        serial_write("ping");
        sleep(1);
    } while(serial_read());
    commander_fill_report("send","My hovercraft is full of eels",1);
    printf(json_report);
    //Start lightningd here:
}
