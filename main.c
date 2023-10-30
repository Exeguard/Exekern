#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>

static struct kprobe kp;

static int pre_proc_handler(struct kprobe *probe, struct pt_regs *regs) {
  char *filename = (char *)regs->si;

  printk(KERN_INFO "Executing: %s\n", filename);

  // TODO: Implement conditional cancel of execution.

  // Continue executing
  return 0;
}

static int __init exekern_init(void) {
  printk(KERN_INFO "Launching Exekern kprobe...\n");

  kp.pre_handler = pre_proc_handler;
  kp.symbol_name = "sys_execve";

  printk(KERN_INFO "Setup kprobe information...\n");

  int kprobe_result = register_kprobe(&kp);

  if (kprobe_result < 0) {
    printk(KERN_ERR "Kprobe registration failed! Exit code: %d\n", kprobe_result);
    return -1;
  }

  printk(KERN_INFO "Loaded Exekern.\n");

  return 0;
}

static void __exit exekern_exit(void) {
  printk("Removing Exekern kprobe...");
  unregister_kprobe(&kp);

  printk(KERN_INFO "Unloaded Exekern.\n");
}

module_init(exekern_init);
module_exit(exekern_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ben McAvoy");
MODULE_DESCRIPTION("A kernel module for managing execution of programs.");
