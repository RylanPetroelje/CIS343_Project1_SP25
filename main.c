#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_lib.h"

#define HEADER_SIZE 44

int main(int argc, char** argv){
    char* contents;
    size_t num_bytes = read_file(argv[1], &contents);
    char* data = contents + HEADER_SIZE;
    size_t data_size = num_bytes - HEADER_SIZE;

    printf("%s\n", argv[1]);
    printf("%lu bytes read.\n", num_bytes);

    int num_channels = *(contents + 22);
    int  bits_per_sample = *(contents + 34);
    int bytes_per_sample = (bits_per_sample / 8) * num_channels;

    printf("Channels: %u\n", num_channels);
    printf("Bits per sample: %u\n", bits_per_sample);
    printf("Bytes per sample (Total): %d\n", bytes_per_sample);

    // Reverse the data
    for (size_t i = 0; i < data_size / 2; i += bytes_per_sample) {
        for (int j = 0; j < bytes_per_sample; j++) {
            char tmp = data[i + j];
            data[i + j] = data[data_size - bytes_per_sample - i + j];
            data[data_size - bytes_per_sample - i + j] = tmp;
        }
    }

    // Write the file to the output
    write_file(argv[2], contents, num_bytes);

    free(contents); // Always free allocated memory
    return 0;
}
