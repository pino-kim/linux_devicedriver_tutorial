/*  
 *  hello-3.c - Illustrating the __init, __initdata and __exit macros.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

/* 
 * insert __initdata between the variable name and equal 
 * initialized data(__initdata) and function(__init) are used only
 * during the initialized phase and free up used memory resources after  	
 */
static int hello3_data __initdata = 3;	

static int __init hello_3_init(void)
{
	printk(KERN_INFO "Hello, world %d\n", hello3_data);
	return 0;
}

static void __exit hello_3_exit(void)
{
	printk(KERN_INFO "Goodbye, world 3\n");
}

module_init(hello_3_init);	/* Driver initialization entry point */
module_exit(hello_3_exit);	/* Driver exit entry point */
