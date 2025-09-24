#ifndef WAV_C
#define WAV_C

#include "wav.h"

int setWavHeader(char* contents, wav_header* wav) {

    wav.sampleRate = *(int*)(contents + 24);
    wav.channel = *(int*)(contents + 22);
    wav.bitsPerSample = *(int*)(contents + 34);

    printf("Sample Rate: %d\n", wav.sampleRate);
    printf("Channels: %d\n", wav.channels);
    printf("Bits per sample: %d\n", wav.bitsPerSample);

    return 1;
}

int defineHeaderDetails(char** file, wav_header* wavHeader, wav_file* wavFile) {
    char* data;
    read_file(file, &data);

    setWavHeader(data, wavHeader);

    wavFile.fileSize = read_file(file, &wavFile.data);
    wavFile.header = wavHeader;

    return 1;
}

#endif