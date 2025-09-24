#include "wav.h"

int setWavHeader(char** file, wav_header* wav) {
    char* contents;
    size_t num_bytes = read_file(file, &contents);
    char* data = contents + 44;
    size_t data_size = num_bytes - HEADER_SIZE;

    wav.sampleRate = *(int*)(contents + 24);
    wav.channel = *(contents + 22);
    wav.bitsPerSample = *(contents + 34);

    printf("Sample Rate: %d\n", wav.sample_rate);
    printf("Channels: %d\n", wav.channels);
    printf("Bits per sample: %d\n", wav.bitsPerSample);

    return 1;
}