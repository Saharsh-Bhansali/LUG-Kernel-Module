#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saharsh Bhansali");
MODULE_DESCRIPTION("Hello Kernel");
MODULE_VERSION("3");

static char* message = "Hello, World";
static int words=1;

module_param(words, int, S_IRUGO);
module_param(message, charp, S_IRUGO);

static int __init tryinit(void){

	//char str[12]={"H","e","l","l","o",",","W","o","r","l","d"};
	for(int i = 0;i<words;++i){
		pr_info("%s",str[i]);
	}
	return 0;
}

static void __exit ex_exit(void){printk(KERN_INFO "Byeeee, World");}

//module_init(ex_init);
module_init(tryinit);
module_exit(ex_exit);

