#define PORT 0x3F8
#include <stdint.h>
#include <stddef.h>
#include "serial.h"

static inline void outb(unsigned short port, unsigned char val) {
    // Uses the x86 'out' instruction to send 'val' (al) to 'port' (dx)
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

void serial_write_char(const char c){
    outb(PORT, c);
}

void kprint(const char *str) {
    size_t i = 0;
    while(*str) {
        serial_write_char(str[i++]);
    }
}