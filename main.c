#include <linux/module.h>
#include <linux/kernel.h>

static int __init exekern_init(void) {
    printk(KERN_INFO "Loaded Exekern.\n");

    return 0;
}

static void __exit exekern_exit(void) {
    printk(KERN_INFO "Unloaded Exekern.\n");
}

module_init(exekern_init);
module_exit(exekern_exit);

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Ben McAvoy");
MODULE_DESCRIPTION("A kernel module for managing execution of programs.");
