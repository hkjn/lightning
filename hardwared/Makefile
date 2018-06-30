CC=gcc

hardware: hardware.o serial.o
	$(CC) hardware.o serial.o flags.o -o hardware

serial.o: serial.c serial.h
	$(CC) -c serial.c -o serial.o

flags.o: flags.c flags.h
	$(CC) -c flags.c -o flags.o

hardware.o: hardware.c serial.h flags.h
	$(CC) -c hardware.c -o hardware.o


