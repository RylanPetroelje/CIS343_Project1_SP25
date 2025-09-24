'''
Define Structs
Task: Define WavFormat and WavFile structs.
Hint: Use a pointer for the data array because audio length is variable.
'''
struct __attribute__((packed)) WavFormat{
  unsigned int sampleRate;
  int channel;
  int bitsPerSample;
  WavFile* wavFile;
};
 
struct __attribute__((packed)) WavFile{
  uint8_t* data
};

'''
Allocate and Fill Data
Task: Allocate memory for data using malloc.
Hint: 1 second of stereo audio at 44100 Hz, 16-bit samples → 44100 * 2 * 2 bytes.
Fill with dummy values (e.g., i % 256) and print first 10 values.
'''
struct WavFormat format1;
format1.sampleRate = 44100;
format1.channel = 2;
format1.bytesPerSample = 2;
 
struct WavFile file1;
format1.wavFile = file1;
file1.data = malloc(wavFormat.sampleRate * file1.channel * file1.bytesPerSample);

'''
Optional Challenge: Multiple Tracks
Task: Extend to MultiTrackWav with multiple Track structs.
Hints:
Each track has its own dynamic samples array.
Free each track’s samples before freeing the tracks array.
'''
struct __attribute__((packed)) Track {
  uint8_t* samples;
  size_t numSamples;
};
 
struct __attribute__((packed)) MultiTrackWav {
  struct WavFormat format;
  struct Track *tracks;
  int numTracks
};
 
...
 
int main() {
  //define file format
  struct WavFormat format1;
  format1.sampleRate = 44100;
  format1.channels = 2;
  format1.bytesPerSample = 2;
  
  //define Track list
  struct MultiTrackWav m;
  m.format = format1
  m.numTracks = 5
  m.tracks = malloc(m.numTracks * sizeof(struct Track));
 
  int durationSeconds = 1;
  size_t numSamples = format1.sampleRate * durationSeconds;
 
  //fills tracks with samples
  for (int i=0; i < m.numTracks; t++) {
    m.tracks[i].numSamples = numSamples;
    m.tracks[i].samples = malloc(numSamples * format1.bytesPerSample);
 
  memset(multi.tracks[t].samples, 0, numSamples * bytesPerSample);
 
  for (int i=0; t < m.numTracks; i++) { 
    free(m.tracks[i].samples);
  }
  free(m.tracks)
 
  return 0;
 
}

