#include "serial.h"
#include <string.h>
#include <unistd.h>
#include "yajl/src/api/yajl_tree.h"
//#include "flags.h"

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


void commander_fill_report(const char *request)
{
    char *p = json_report;
    snprintf(p + strlens(json_report), COMMANDER_REPORT_SIZE - strlens(json_report),
            "{\"request\":\"%s\"}\n", request);
}

const char *commander_parse(const char *command)
{
    yajl_val value, json_node;
    const char *success = "success";
    char errbuf[1024];
    json_node = yajl_tree_parse((const char*) command, errbuf, sizeof(errbuf));
    //for (int cmd = 0; cmd < CMD_NUM; cmd++) {
    if (json_node == NULL)
	{
		fprintf(stderr, "parse_error: ");
        if (strlen(errbuf)) fprintf(stderr, " %s", errbuf);
        else fprintf(stderr, "unknown error");
        fprintf(stderr, "\n");
        return 1;
    }
    const char *status[] = { "status", (const char *) 0 };
    const char *payload[] = { "payload", (const char *) 0 };
    const char *cStatus = YAJL_GET_STRING(yajl_tree_get(json_node, status, yajl_t_string));
    const char *cPayload = YAJL_GET_STRING(yajl_tree_get(json_node, payload, yajl_t_string));
    if (strcmp(cStatus,success))
    {
        fprintf(stderr, "Failure received from HSM %s", cPayload);
    }
    return cPayload;
}

int main(int argc, char* argv[])
{
    //Wait for the hardware to be plugged in
    do {
        serial_write("ping");
        sleep(1);
    } while(serial_read());
    commander_fill_report("My hovercraft is full of eels");
    serial_write(json_report);
    serial_read();
    serial_read();
    const char* response = commander_parse("{\"status\":\"success\",\"payload\":\"My hovercraft is full of eels\"}");
    printf(response);
    //Start lightningd here:
}
