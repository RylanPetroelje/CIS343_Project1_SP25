#ifndef WAV_C
#define WAV_C

#include "wav.h"

int setWavHeader(char* contents, wav_header* wav) {

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