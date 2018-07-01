CC=gcc -g

hardware: hardware.o serial.o yajl/yajl-2.1.1/lib/libyajl_s.a
	$(CC) hardware.o yajl/yajl-2.1.1/lib/libyajl_s.a serial.o -o hardware

serial.o: serial.c serial.h
	$(CC) -c serial.c -o serial.o

hardware.o: hardware.c serial.h yajl/yajl-2.1.1/include/yajl/yajl_common.h yajl/yajl-2.1.1/include/yajl/yajl_parse.h yajl/yajl-2.1.1/include/yajl/yajl_tree.h
	$(CC) -c hardware.c -o hardware.o


