#include "common.h"
typedef struct registers
{
	uint32 ds;
	uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32 int_no, err_code;
	uint32 eip, cs, eflafs, useresp, ss;
} registers_t;

#define IRQ0 32
#define IRQ15 47

typedef void(*isr_t)(registers_t);
void register_interrupt_handler(uint8 n, isr_t handler);