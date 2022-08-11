#define VGA_ADDRESS 0xB8000
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define RED 4
#define BROWN 6
#define GRAY 7
#define YELLOW 14
#define WHITE 15

unsigned short *terminal_buffer;
unsigned int vga_index;

void print_color_string(char *str, unsigned char color)
{
    int index = 0;
    while (str[index]) {
            terminal_buffer[vga_index] = (unsigned short)str[index]|(unsigned short)color << 8;
            index++;
            vga_index++;
    }
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
}

void clear_screen(void)
{
    int index = 0;

    while (index < 80 * 25 * 2) {
    	terminal_buffer[index] = ' ';
    	index += 2;
    }
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    vga_index = 0;
}

void print_string(char *str)
{
    unsigned char color = WHITE;
    int index = 0;
    while (str[index]) {
            terminal_buffer[vga_index] = (unsigned short)str[index]|(unsigned short)color << 8;
            index++;
            vga_index++;
    }
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
}
