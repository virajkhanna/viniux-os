#include "../drivers/screen.c"
#include "../sys/power.c"
#include "../sys/panic.c"
#include "../drivers/ports.c"
#include "../sys/string.c"
#include "../sys/function.h"
#include "util.c"

void kmain(void)
{
    clear_screen();
    print_string("ViniuxOS DOS 1.0 - Made by Viraj Khanna");
    vga_index = 160;
    print_string("Hi!");
    vga_index = 320;
    print_string("Welcome to ViniuxOS-DOS");
    vga_index = 480;
    print_string("Automatically logged in as root");
    vga_index = 640;
    print_string("root@viniuxos-pc:~ ");
    return;
}
