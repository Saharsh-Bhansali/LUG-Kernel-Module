//This is a working copy. Replace (cp ./version.c ./ker-mod.c) and then use make to compile it without having to make edits to the makefile
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// this is the basic information about the module. The modinfo command would return this info when invoked. (Not tested yet.)
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saharsh Bhansali");
MODULE_DESCRIPTION("Hello Kernel");
MODULE_VERSION("2");

// function is run upon loading module using insmod
static int __init tryinit(void){
	// did this after some inspiration and a breakthrough from working on ver 3
	int i=0;
	char * str = "Hello, World";
	while(i<12){
		pr_info("%c",str[i]);
		i++;
	}
	return 0;
}

// function is run upon unloading the module using rmmod
static void __exit ex_exit(void){
	pr_info("Byeeee, World");
}

// from what I know, these are macros, probably from the header files that were included
module_init(tryinit);
module_exit(ex_exit);
