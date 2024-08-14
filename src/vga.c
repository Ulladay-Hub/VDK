#include "vga.h"

#define VGA_TEXT_MODE_BASE 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

void print(const char* str, int row, int col, uint8_t color) {
    uint16_t* vga_buffer = (uint16_t*) VGA_TEXT_MODE_BASE;
    int index = row * VGA_WIDTH + col;

    while (*str) {
        if (index >= VGA_WIDTH * VGA_HEIGHT) {
            return;
        }
        vga_buffer[index] = (*str | (color << 8));
        str++;
        index++;
    }
}

void clear_screen() {
    uint16_t* vga_buffer = (uint16_t*) VGA_TEXT_MODE_BASE;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga_buffer[i] = (VGA_COLOR_BLACK << 8) | ' ';
    }
}
