#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_COLOR_BLACK 0x00
#define VGA_COLOR_WHITE 0x07

void print(const char* str, int row, int col, uint8_t color);
void clear_screen();

#endif // VGA_H
