#include "print.h"
#include "draw.h"
#include "interrupts.h"

void kernel_main() {
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLUE);
    print_clear();
    print_str("MazeInstance Kernel - By the MazeGroup Research Institute - 2024\n");

    set_graphics_mode();

    putpixel(20, 20, 0x2F);

    // Initialiser l'IDT pour gérer les interruptions clavier
    /*idt_install();

    // Activer les interruptions
    asm volatile ("sti");

    // Boucle principale du kernel
    while (1) {
        // Le système attend les interruptions
        asm volatile ("hlt");
    }*/
}