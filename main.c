#include <linux/module.h>
#include <linux/kernel.h>

static int __init mod_init(void) {
    printk(KERN_INFO "Hello, world!\n");
    return 0;
}

static void __exit mod_exit(void) {
    printk(KERN_INFO "Goodbye, world!\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Ben McAvoy");
MODULE_DESCRIPTION("A kernel module to handle execution policies.");
