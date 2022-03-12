#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saharsh Bhansali");
MODULE_DESCRIPTION("Hello Kernel");
MODULE_VERSION("1");

char str[]="Hello, World";

static int __init ex_init(void){printk(KERN_INFO "Hello, World");return 0;}

static int __init ex_init_two(char str[12]){
	int i=0;
	for(i=0;i<12;i++){
		printk(KERN_INFO "%c",str[i]);
	}
	return 0;
}

static void __exit ex_exit(void){printk(KERN_INFO "Byeeee, World");}

module_init(ex_init);
//module_init(ex_init_two(str));
module_exit(ex_exit);

