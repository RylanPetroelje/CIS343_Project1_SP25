#ifndef WAV_H
#define WAV_H

#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((packed)) {
    unsigned int sampleRate;
    int channel;
    int bitsPerSample;
    WavFile* wavFile;
} wav_header;
 
typedef struct __attribute__((packed)) {
    uint8_t* data
} wav_file;

wav_header setWavHeader(char** wav_file);

wav_file defineHeaderDetails(char** wav_file);

wav_file reverseWavFile();

