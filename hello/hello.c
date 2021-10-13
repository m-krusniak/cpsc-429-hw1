// Mel Krusniak - a simple kernel module for Part 1

#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int init_module() {
	// printk doesn't seem to respect urgency levels correctly when I run it
	//    causing the output to not appear from dmesg
	// pr_alert works as an alternative for alert level logging
	pr_alert("Hello world!\n");
	return 0;

}

void cleanup_module() {
	pr_alert("Goodbye world!\n");
}