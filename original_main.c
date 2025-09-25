#include <stdio.h>
#include <stdlib.h>
#include "wav.h"

int main(int argc, char** argv){
    wav_header wavHeader;
    wav_file wavFile;

    defineHeaderDetails(argv[1], &wavHeader, &wavFile);
    reverseWavFile(&wavFile, argv[2]);

    free(wavFile.data); // Always free allocated memory
    return 0;
}
