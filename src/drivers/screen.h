#pragma once

#define WHITE_ON_BLACK 0x0f
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5
#define VGA_ADDRESS 0xB8000
#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define RED 0x04
#define BROWN 0x06
#define GRAY 0x07
#define YELLOW 0x0e
#define WHITE 0x0f
#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0

unsigned short *terminal_buffer;
unsigned int vga_index;

void print_string(char *string);

void print_nl();

void clear_screen();

int scroll_ln(int offset);

void print_backspace();
