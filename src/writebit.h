#ifndef WRITEBIT_H
#define WRITEBIT_H

#include <stdint.h>
#include <stdio.h>

int write_bit(int value, uint8_t *bitstream_buffer, int *bit_count, FILE *output);

#endif