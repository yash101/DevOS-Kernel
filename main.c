#include "sys/monitor.h"
#include "sys/descriptor_tables.h"
#include "sys/timer.h"
int main(struct multiboot *muxboot_ptr)
{
	init_descriptor_tables();
	monitor_clear();
	monitor_write("Hello, World!\n");
	asm volatile("int $0x3");
	asm volatile("int $0x4");
	asm volatile("sti");
	init_timer(1000);
	return 0xDEADBABA;
}