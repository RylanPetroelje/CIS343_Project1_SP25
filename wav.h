#ifndef WAV_H
#define WAV_H

#include <stdint.h>
#include <stddef.h>
#include "file_lib.h"

typedef struct __attribute__((packed)) {
    char riff[4]; // will store first 4 bytes; should be RIFF
    char wav[4]; // will store bytes 8-11; should be WAVE
    unsigned int sampleRate;
    int channels; //will store whether file in mono or stereo; should be stereo
    int bitsPerSample;
    WavFile* wavFile;
} wav_header;
 
typedef struct __attribute__((packed)) {
    wav_header* header;
    size_t fileSize;
    uint8_t* data;
} wav_file;

int setWavHeader(char** file, wav_header* wav);

wav_file defineHeaderDetails(char** wav_file);

void reverseWavFile(wav_file* wav);


#endif