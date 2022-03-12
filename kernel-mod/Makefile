# use `make` to run and compile the module
# then use `sudo make test` to load module, get logs and unload it.

# taken directly from a resource: https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234

obj-m += ker-mod.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	sudo dmesg -C
	sudo insmod ker-mod.ko
	sudo rmmod ker-mod.ko
	dmesg
