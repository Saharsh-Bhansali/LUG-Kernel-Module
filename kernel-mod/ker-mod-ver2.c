#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saharsh Bhansali");
MODULE_DESCRIPTION("Hello Kernel");
MODULE_VERSION("2");


//static int __init ex_init(void){printk(KERN_INFO "Hello, World");return 0;}

static int __init tryinit(void){
	int i=0;
	//char str[12]={"H","e","l","l","o",",","W","o","r","l","d"};
	char * str = "Hello, World";
	while(i<12){
		pr_info("%c",str[i]);
		i++;
	}
	return 0;
}

static void __exit ex_exit(void){pr_info("Byeeee, World");}

//module_init(ex_init);
module_init(tryinit);
module_exit(ex_exit);

