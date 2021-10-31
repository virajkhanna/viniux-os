#include "sys/power.c"
#include "sys/screen.c"
#include "sys/panic.c"
#include "sys/ports.c"
#include "sys/string.c"
#include "sys/function.h"

void main(void)
{
    clear_screen();
    print_string("Hi!");
    vga_index = 80;
    print_string("Welcome to ViniuxOS DOS 1.0");
    vga_index = 240;
    print_string("Automatically logged in as root");
    vga_index = 400;
    print_string("root@viniuxos-pc:~ ");
    vga_index = 480;
    return;
}
