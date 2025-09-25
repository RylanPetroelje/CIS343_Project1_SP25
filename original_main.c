#include <stdio.h>
#include <stdlib.h>
#include "wav.h"

int main(int argc, char** argv){
    wav_header wavHeader;
    wav_file wavFile;

    printf("Input File Name: %s\n", argv[1]);
    printf("Output File Name: %s\n", argv[2]);

    defineHeaderDetails(argv[1], &wavHeader, &wavFile);

    printf("File Size: %lu\n", wavFile.fileSize);
    printf("Sample Rate: %d\n", wavHeader.sampleRate);
    printf("Channels: %d\n", wavHeader.channels);
    printf("Bits per sample: %d\n\n", wavHeader.bitsPerSample);
    printf("Starting Reversal...\n");

    reverseWavFile(&wavFile, argv[2]);

    printf("Done Reversing!\n");
    printf("Reversed file written to %s\n", argv[2]);

    free(wavFile.data); // Always free allocated memory
    return 0;
}
