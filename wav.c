#ifndef WAV_C
#define WAV_C

#include "wav.h"

int setWavHeader(char** file, wav_header* wav) {
    char* contents; // we need to allocate memory for this buddy
    read_file(file, &contents);
    
    if (*(content) == 'R' || *(content + 1) == 'I' || *(content + 2) == 'F' || *(content + 3) == 'F') {
        printf("File is not RIFF subtype");
        return -1;
    }

    if (*(content + 8) == 'W' || *(content + 9) == 'A' || *(content + 10) == 'V' || *(content + 11) == 'E') {
        printf("File is not WAV");
        return -1
    }

    if (*(content + 20) != 1) {
        printf("Format type is not 1");
        return -1;
    }

    if (*(content + 22) != 2) {
        printf("File is not in stereo");
        return -1;
    }

    wav.sampleRate = *(int*)(contents + 24);
    wav.channel = *(contents + 22);
    wav.bitsPerSample = *(contents + 34);

    printf("Sample Rate: %d\n", wav.sample_rate);
    printf("Channels: %d\n", wav.channels);
    printf("Bits per sample: %d\n", wav.bitsPerSample);

    return 1;
}