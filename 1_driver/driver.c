/*
 *			
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */
#include <linux/device.h>

MODULE_LICENSE("Dual BSD/GPL");

static void my_release(struct device *dev)
{
	printk(KERN_INFO "my_release");
}

struct mydevice {
	struct device dev;
	int id;
};

struct mydevice chdev = {
	.id = 1,
	.dev = {
		.init_name = "chdev",
		.release = my_release,
	}
};

static int __init hello_init(void)
{
	int ret = 0;
	printk(KERN_INFO "device register\n");
	
	ret = device_register(&chdev.dev);
	printk(KERN_INFO "ret %d\n", ret);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye, world\n");
	device_unregister(&chdev.dev);
}

module_init(hello_init);
module_exit(hello_exit);
