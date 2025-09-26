#ifndef WAV_C
#define WAV_C

#include "wav.h"

int setWavHeader(char* contents, wav_header* wav) {

    if (*(contents) == 'R' || *(contents + 1) == 'I' || *(contents + 2) == 'F' || *(contents + 3) == 'F') {
        printf("File is not RIFF subtype\n");
        return -1;
    }

    if (*(contents + 8) == 'W' || *(contents + 9) == 'A' || *(contents + 10) == 'V' || *(contents + 11) == 'E') {
        printf("File is not WAV\n");
        return -1;
    }

    if (*(contents + 20) != 1) {
        printf("Format type is not 1\n");
        return -1;
    }

    if (*(contents + 22) != 2) {
        printf("File is not in stereo\n");
        return -1;
    }

    wav->sampleRate = *(int*)(contents + 24);
    wav->channels = *(int*)(contents + 22);
    wav->bitsPerSample = *(int*)(contents + 34);

    return 0;
}

int defineHeaderDetails(char* file, wav_header* wavHeader, wav_file* wavFile) {
    char* data;
    read_file(file, &data);

    if (setWavHeader(data, wavHeader) == -1){
        return -1;
    };

    wavFile->fileSize = read_file(file, &wavFile->data);
    wavFile->header = wavHeader;

    return 0;
}

int reverseWavFile(wav_file* wav, char* file_path) {
    int bytes_per_sample = (wav->header->bitsPerSample / 8) * wav->header->channels;
    size_t data_size = wav->fileSize - 44;
    char* data = wav->data + 44;
    
    for (size_t i = 0; i < data_size / 2; i += bytes_per_sample) {
        for (int j = 0; j < bytes_per_sample; j++) {
            char tmp = data[i + j];
            data[i + j] = data[data_size - bytes_per_sample - i + j];
            data[data_size - bytes_per_sample - i + j] = tmp;
        }
    }

    write_file(file_path, wav->data, wav->fileSize);

    return 0;
}


#endif