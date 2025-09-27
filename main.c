#include <stdio.h>
#include <stdlib.h>
#include "wav.h"

int main(int argc, char** argv){
    
    //printf("%d", argc);
    //invalid arguments
    if (argc != 3) {
        printf("Invalid format. Try %s <input_file.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    wav_header wavHeader;
    wav_file wavFile;

    printf("Input File Name: %s\n", argv[1]);
    printf("Output File Name: %s\n", argv[2]);

    if (defineHeaderDetails(argv[1], &wavHeader, &wavFile) == -1) {
        printf("Invalid Header Format\n");
        return -1;
    };

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
