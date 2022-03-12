//This is a working copy. Replace (cp ./version.c ./ker-mod.c) and then use make to compile it without having to make edits to the makefile
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// this is the basic information about the module. The modinfo command would return this info when invoked. (Not tested yet.)
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saharsh Bhansali");
MODULE_DESCRIPTION("Hello Kernel");
MODULE_VERSION("3");

static char* message = "Hello, World";
static int words=1;

// directly taken from the gfg resources. 
module_param(words, int, S_IRUGO);
module_param(message, charp, S_IRUGO);

// function is run upon loading module using insmod
static int __init tryinit(void){
	// referred to gfg resource and made a few modifications and changes
	for(int i = 0;i<words;++i){
		pr_info("%s",str[i]);
	}
	return 0;
}

// function is run upon unloading the module using rmmod
static void __exit ex_exit(void){
	printk(KERN_INFO "Byeeee, World");
}

// from what I know, these are macros, probably from the header files that were included
module_init(tryinit);
module_exit(ex_exit);
