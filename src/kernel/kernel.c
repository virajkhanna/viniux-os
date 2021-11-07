#include "../drivers/screen.c"
#include "../sys/power.c"
#include "../sys/panic.c"
#include "../drivers/ports.c"
#include "../sys/string.c"
#include "../sys/function.h"
#include "util.c"
#include "../cpu/isr.c"

void user_input(char *input);

#include "../drivers/keyboard.c"

void kmain(void)
{
    __asm__("cli");
    clear_screen();
    print_string("ViniuxOS DOS 1.0 - Made by Viraj Khanna");
    vga_index = 80;
    print_string("Copyright 2021-Present @ The ViniuxOS Developers");
    vga_index = 240;
    print_string("Hi!");
    vga_index = 320;
    print_string("Welcome to ViniuxOS-DOS 1.0");
    vga_index = 480;
    print_string("Automatically logged in as root");
    vga_index = 640;
    print_color_string("Loaded IDT and ISR", GREEN);  
    isr_install();
    vga_index = 800;
    print_string("root@viniuxos-pc:~ ");
    init_keyboard();
    return;
}


void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        print_string("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }
    print_string("You said: ");
    print_string(input);
    print_string("\n> ");
}
