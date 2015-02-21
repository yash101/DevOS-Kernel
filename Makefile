SOURCES=boot.o main.o sys/monitor.o sys/common.o sys/descriptor_tables.o sys/isr.o sys/interrupt.o sys/gdt.o sys/timer.o

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-Tlink.ld -m elf_i386
ASFLAGS=-felf

all: $(SOURCES) link

clean:
	rm *.o kernel_binary

link:
	ld $(LDFLAGS) -o kernel_binary $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<