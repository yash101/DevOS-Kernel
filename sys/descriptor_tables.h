#ifndef DESCRIPTOR_TABLES_H
#define DESCRIPTOR_TABLES_H
#include "common.h"
void init_descriptor_tables();

//Contains a GDT entry value.
struct gdt_entry_structure
{
	uint16 limit_low;
	uint16 base_low;
	uint8 base_middle;
	uint8 access;
	uint8 granularity;
	uint8 base_high;
} __attribute__((packed));
typedef struct gdt_entry_structure gdt_entry_t;

//Describes a pointer to a GDT. Points to the start
//of the array of GDT entries
struct gdt_ptr_struct
{
	uint16 limit;
	uint32 base;
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;


//Describes an interrupt gate
struct idt_entry_struct
{
	uint16 base_lo;
	uint16 sel;
	uint8 always0;
	uint8 flags;
	uint16 base_hi;
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

//Contains describint pointer to array of interrupt handlers
//required for the lidt instructuon
struct idt_ptr_struct
{
	uint16 limit;
	uint32 base;
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();
#endif