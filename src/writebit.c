#include "writebit.h"

int write_bit(int value, uint8_t *bitstream_buffer, int *bit_count, FILE *output)
{
    if (value != 0 && value != 1) {
        return -1; // Invalid value, must be 0 or 1
    }

    *bitstream_buffer = (*bitstream_buffer << 1) | value;
    (*bit_count)++;

    if (*bit_count == 8) {
        if (flush_byte(bitstream_buffer, output) != 0) {
            return -1; // Error flushing byte
        }
        *bit_count = 0;
    }
    return 0; 
}



static int flush_byte(uint8_t *bitstream_buffer, FILE *output)
{
    if (fputc(*bitstream_buffer, output) == EOF) {
        return -1; // Error writing to output file
    }

    *bitstream_buffer = 0;

    return 0;
}


// TODO: Add final partial-byte flushing once the
// encoder/decoder file format is defined.



