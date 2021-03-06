#ifndef COMMON_H
#define COMMON_H
typedef unsigned int uint32;
typedef int sint32;
typedef unsigned short uint16;
typedef short sint16;
typedef unsigned char uint8;
typedef char sint8;

void outb(uint16 port, uint8 value);
uint8 inb(uint16 port);
uint16 inw(uint16 port);
#endif
