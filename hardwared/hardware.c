#include "serial.h"
#include <string.h>
#include <unistd.h>
#include "yajl/src/api/yajl_tree.h"
//#include "flags.h"

#define COMMANDER_REPORT_SIZE       3584
#define COMMANDER_NUM_SIG_MIN       14// Must be >= desktop app's `MAX_INPUTS_PER_SIGN` !!
#define COMMANDER_SIG_LEN           154// sig + recid + json formatting
#define COMMANDER_ARRAY_MAX         (COMMANDER_REPORT_SIZE - (COMMANDER_SIG_LEN * 8))// Multiple is emperically found such that NUM_SIG_MIN is maximum

static int REPORT_BUF_OVERFLOW = 0;

const char *commander_parse(char *buf)
{
    yajl_val value, json_node;
    const char *success = "success";
    char errbuf[1024];
    json_node = yajl_tree_parse(buf, errbuf, sizeof(errbuf));
    //for (int cmd = 0; cmd < CMD_NUM; cmd++) {
    if (json_node == NULL)
	{
		fprintf(stderr, "parse_error: ");
        if (strlen(errbuf)) fprintf(stderr, " %s", errbuf);
        else fprintf(stderr, "unknown error");
        fprintf(stderr, "\n");
        return "failed to parse payload";
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
    char buf[1024] = {[0 ... 1023] = 0};
    size_t length = strlen(buf);
    //Wait for the hardware to be plugged in
    do {
        sleep(1);
        serial_write("{\"request\":\"ping\"}");
    } while(serial_read(buf, length));

    serial_write("{\"request\":\"get_hsm_secret\"}");
    sleep(1);
    memset(buf, 0, 1024);
    serial_read(buf);
    const char* response = commander_parse(buf);
    printf(response);
    //Start lightningd here:
}
