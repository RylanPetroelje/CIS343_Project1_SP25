#include "wav.h"

int setWavHeader(char** file, wav_header* wav) {
    char* contents;
    read_file(file, &contents);

    wav.sampleRate = *(int*)(contents + 24);
    wav.channel = *(contents + 22);
    wav.bitsPerSample = *(contents + 34);

    printf("Sample Rate: %d\n", wav.sample_rate);
    printf("Channels: %d\n", wav.channels);
    printf("Bits per sample: %d\n", wav.bitsPerSample);

    return 1;
}