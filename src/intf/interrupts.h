/*#include <stdint.h>
#include "print.h"

// Déclaration de la table des descripteurs d'interruptions
extern void load_idt(uint32_t);

// Structure pour un descripteur d'interruption
struct idt_entry {
    uint16_t base_low;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

// Structure pour la table IDT
struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Table IDT
struct idt_entry idt[256];
struct idt_ptr idtp;

// Fonction pour définir une entrée dans la table IDT
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

// Table de correspondance des codes de scan vers les caractères ASCII
char scancode_to_ascii[] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', // Backspace
    '\t', // Tab
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', // Enter
    0, // Control
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0, // Left Shift
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, // Right Shift
    '*',
    0, // Alt
    ' ', // Space
    0, // Caps Lock
    // Les autres codes de scan peuvent être ajoutés ici
};

// Initialisation de l'IDT
void idt_install() {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32_t)&idt;

    // Remplir la table IDT avec des gestionnaires d'interruptions
    idt_set_gate(33, (uint32_t)keyboard_handler, 0x08, 0x8E);

    // Charger la table IDT
    load_idt((uint32_t)&idtp);
}

// Fonction pour lire un octet depuis un port
static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

// Fonction pour écrire un octet vers un port
static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

void keyboard_handler() {
    // Lire le code de scan du port du clavier
    uint8_t scancode = inb(0x60);

    // Vérifier si le code de scan est dans la plage de notre table
    if (scancode < sizeof(scancode_to_ascii)) {
        char ascii = scancode_to_ascii[scancode];
        if (ascii) {
            print_char(ascii);
        }
    }

    // Envoyer un signal de fin d'interruption au PIC
    outb(0x20, 0x20);
}*/