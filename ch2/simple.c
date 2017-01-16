#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

void print_int(int *int_to_print)
{
	int i;
	int num_prints;

	if (int_to_print == NULL)
		return;

	num_prints = *int_to_print;

	for (i = 0;
	     i < num_prints;
	     ++i) {
		printk(KERN_INFO "My magic function is printing int_to_print:"
				" 0x%pK, *int_to_print: 0x%x\n",
				int_to_print,
				*int_to_print);
	}
}

/* This function is called when the module is loaded. */
int simple_init(void)
{
	printk(KERN_INFO "Loading Module\n");

	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	int int_to_print = 3;
	print_int(&int_to_print);

	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
