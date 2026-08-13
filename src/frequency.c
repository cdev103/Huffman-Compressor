#include "frequency.h"

int calculate_frequencies(FILE *input, int counts[256]) {
    // Initialize the counts array to zero
    for (int i = 0; i < 256; i++) {
        counts[i] = 0;
    }

    // Read each byte from the input file and update the counts
    int byte;
    while ((byte = fgetc(input)) != EOF) {
        counts[byte]++;
    }

    return 0; // Return 0 to indicate success
}