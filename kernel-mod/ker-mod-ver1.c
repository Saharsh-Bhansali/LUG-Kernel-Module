//This is a wroking copy. Replace (cp ./version.c ./ker-mod.c) and then use make to compile it without having to make edits to the makefile

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// this is the basic information about the module. The modinfo command would return this info when invoked. (Not tested yet.)
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saharsh Bhansali");
MODULE_DESCRIPTION("Hello Kernel");
MODULE_VERSION("1");


char str[]="Hello, World";

// function is run upon loading module using insmod
static int __init ex_init(void){
	printk(KERN_INFO "Hello, World");
	return 0;
}

// function is run upon unloading the module using rmmod
static void __exit ex_exit(void){
	printk(KERN_INFO "Byeeee, World");
}

// from what I know, these are macros, probably from the header files that were included
module_init(ex_init);
module_exit(ex_exit);
