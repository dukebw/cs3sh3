#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

/*
 * This function is called when the module is loaded.
 *
 * Note that there is ambiguity in question 1 of this assignment, since it
 * refers to the idle task (pid 0) and init_task (pid 1) interchangeably.
 * `for_each_process` starts with init_task. If pid 0 were wanted to be
 * printed, one could still use `for_each_process`, with special treatment to
 * get pid 0, e.g.
 *
 * if (task->pid == 1) printk(KERN_INFO "pid: %d", task->parent->pid);
 */
int print_init_task_struct_init(void)
{
	struct task_struct *task = current;
	for_each_process(task) {
		printk(KERN_INFO "Name: %s, pid: %d", task->comm, task->pid);
	}

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
MODULE_AUTHOR("Brendan Duke");
