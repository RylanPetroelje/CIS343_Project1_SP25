#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_lib.h"

#define HEADER_SIZE 44

int main(int argc, char** argv){
    // Read the input file
    size_t num_bytes = read_file(argv[1], &contents);
    printf("%s\n", argv[1]);
    printf("%lu bytes read.\n", num_bytes);

    char* contents;
    char* data = contents + WAV_HEADER_SIZE;
    size_t data_size = num_bytes - WAV_HEADER_SIZE;

    // Reverse the data
    for (size_t i = 0; i < data_size / 2; i++) {
        char k = data[i];
        data[i] = data[data_size - 1 - i];
        data[data_size - 1 - i] = k;
    }

    // Write the file to the output
    write_file(argv[2], contents, num_bytes);

    free(contents); // Always free allocated memory
    return 0;
}
