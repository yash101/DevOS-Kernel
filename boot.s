MULTIBOOT_PAGE_ALIGN equ 1 << 0
MULTIBOOT_MEM_INFO equ 1 << 1
MULTIBOOT_HEADER_MAGIC equ 0x1BADB002
MULTIBOOT_HEADER_FLAGS equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEM_INFO
MULTIBOOT_CHECKSUM EQU - (MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

bits 32
global mboot
extern code
extern bss
extern end

mboot:
	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd MULTIBOOT_CHECKSUM
	
	dd mboot
	dd code
	dd bss
	dd end
	dd start

global start
extern main

start:
	push ebx
	cli
	call main
    jmp $
    