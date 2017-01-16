#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

/* This function is called when the module is loaded. */
int print_init_task_struct_init(void)
{
	struct task_struct *init_task_struct = current;
	while ((init_task_struct->pid != 0) && (init_task_struct->pid != 1))
		init_task_struct = init_task_struct->parent;

	printk(KERN_INFO "Loading Module\n");

	printk(KERN_INFO "pid: %d\n", init_task_struct->pid);
	if (init_task_struct->parent)
		printk(KERN_INFO "parent pid: %d\n", init_task_struct->parent->pid);
	printk(KERN_INFO "state: %ld\n", init_task_struct->state);
	printk(KERN_INFO "flags: %u\n", init_task_struct->flags);
	printk(KERN_INFO "runtime priority: %u\n", init_task_struct->rt_priority);
	printk(KERN_INFO "process policy: %u\n", init_task_struct->policy);
	printk(KERN_INFO "tgid: %d\n", init_task_struct->tgid);

	return 0;
}

/* This function is called when the module is removed. */
void print_init_task_struct_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init(print_init_task_struct_init);
module_exit(print_init_task_struct_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
