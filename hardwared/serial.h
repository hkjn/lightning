/*
 * This program sends the string from command line argument argv[1] to the serial port
 * If there are no arguments - sends "Nothing"
 * Can be used to debug communication between hardware device and our hsmd daemon
 * TODO: add serial_read function
 */

#include <stdio.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions      */
#include <errno.h>   /* ERROR Number Definitions           */
#include <string.h>

// write here the serial port you have Arduino plugged to
// should be autodetected afterwards
const char* serialport = "/dev/ttyACM0";

void serial_write(char * msg);
int serial_read();

