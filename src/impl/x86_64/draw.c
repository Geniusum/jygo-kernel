#include "draw.h"
#include <stdint.h>

void set_graphics_mode() {
    // Interruption BIOS pour définir le mode vidéo
    asm volatile (
        "mov $0x13, %ax\n"  // Mode 13h : 320x200 en 256 couleurs
        "int $0x10\n"       // Appel de l'interruption vidéo
    );
}

void putpixel(int pos_x, int pos_y, unsigned char VGA_COLOR)
{
    unsigned char* location = (unsigned char*)0xA0000 + 320 * pos_y + pos_x;
    *location = VGA_COLOR;
}