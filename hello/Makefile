# Mel Krusniak - Makefile for Part 1 kernel module

# Taken from the Linux Kernel Module Programming Guide
#    (https://tldp.org/LDP/lkmpg/2.6/html/x181.html)

obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean