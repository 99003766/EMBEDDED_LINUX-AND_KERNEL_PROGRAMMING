obj-m += simple.o sample.o
KSRC = /lib/modules/$(shell uname -r)/build
all:
	make -C /home/user/kernel/packages/linux-4.14.227.tar.1/linux-4.14.227 M=${PWD} modules ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
clean:
	make -C /home/user/kernel/packages/linux-4.14.227.tar.1/linux-4.14.227 M=${PWD} clean ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
