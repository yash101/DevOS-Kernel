#include "common.h"
void outb(uint16 port, uint8 value)
{
	asm volatile("outb %1, %0" : : "dN" (port), "a" (value));
}

uint8 inb(uint16 port)
{
	uint8 ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

uint16 inw(uint16 port)
{
	uint16 ret;
	asm volatile("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

void memcpy(uint8* dest, const uint8* src, uint32 len)
{
	const uint8* sp = (const uint8*) src;
	uint8* dp = (uint8*) dest;
	for(; len != 0; len--) *dp++ = *sp++;
}

void memset(uint8* dest, uint8* val, uint32 length)
{
	uint8* tmp = (uint8*) dest;
	for(; length != 0; length--) *tmp++ = val;
}

int strcmp(char* str1, char* str2)
{
	int i = 0;
	int failed = 0;
	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if(str1[i] != str2[i])
		{
			failed = 1;
			break;
		}
		i++;
	}
	if(str1[i] == '\0' || str2[i] == '\0') failed = 1;
	return failed;
}

char* strcpy(char* dest, const char* src)
{
	do
	{
		*dest++ = *src++;
	}
	while(*src != 0);
	return dest;
}

char* strcat(char* dest, const char* src)
{
	while(*dest != 0)
	{
		*dest = *dest++;
	}
	do
	{
		*dest++ = *src++;
	}
	while(*src != 0);
	return dest;
}