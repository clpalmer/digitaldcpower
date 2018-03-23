# makefile, written by guido socher
#-------------------
.PHONY: all
all: i2c_rs232_pintest i2ctalk
#
#-------------------
i2c_m.o: i2c_m.h i2c_m.c
	gcc -Wall -c i2c_m.c
i2ctalk_linux.o: i2c_m.h i2ctalk_linux.c 
	gcc -Wall -c i2ctalk_linux.c
i2c_rs232_pintest.o: i2c_m.h i2c_rs232_pintest.c 
	gcc -Wall -c i2c_rs232_pintest.c
#
i2ctalk: i2c_m.o i2ctalk_linux.o 
	gcc -Wall -o i2ctalk i2c_m.o i2ctalk_linux.o
i2c_rs232_pintest: i2c_m.o i2c_rs232_pintest.o 
	gcc -Wall -o i2c_rs232_pintest i2c_m.o i2c_rs232_pintest.o
#-------------------
clean:
	rm -f *.o i2c_rs232_pintest i2ctalk
#-------------------
