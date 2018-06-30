#include "serial.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
    //Wait for the hardware to be plugged in
    do {
        serial_write("ping");
        sleep(1);
    } while(serial_read());
    //Start lightningd
}
