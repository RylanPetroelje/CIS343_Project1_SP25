## Abstract
This is a project I did in collaboration with Seth Perko for our Structure of Programming Class, taken in the FALL'25 semester at GVSU. It took us roughly 4 to 5 hours so create functional code that complies with the requirements stated in `RUBRIK.md`. The goal of project was to successfully reverse an uncompressed stereo WAV file of RIFF subtype in little-endian format.  
## Breakdown of Files
+ `README.md` - A brief overview of the project meant to be a condensed version of `RUBRIK.md`. 
+ `RUBRIK.md` - A more extensive breakdown of the project, factors, and limitations we had to overcome in order to pass the assessment.
+ `Makefile` - A makefile for easily compiling all the components below that includes a clean step because .o files are ugly.
+ `main.c` - The main execution file, using the function defined in `wav.c` and `file_lib.c` and printing the output in the format required by `README.md`
+ `file_lib.h` - A header file for prototyping the functions defined in `file_lib.c`. This file was provided by the instructor.
+ `file_lib.c` - A c file that defines functions we will use to read and write files passed into the program. This file was provided by the instructor.
+ `wav.h` - A header file for creating the structures worked on and prototyping the functions defined in `wav.c`.
+ `wav.c` - A c file that defines the functions for verifying the wavFile, separating and reading information from the header, and reversing the  wavFile.
## Core C Programming Principles Used
+ File I/O
  - Reading and Writing binary files
+ Pointers and Memory Management
  - Dynamic Allocation
  - Memory Deallocation
  - Pointer Arithmetic
+ Data Structures
+ Data Types and Byte-level Manipulation
  - Use of both signed and unsigned integer-types
  - Endianness
  - Sample Swapping
+ Modular Programming
  - Header Files
  - Source Files
+ Error Handling
  - Input Validation
  - File Format Validation
## How to Run
**Compile the program:**
Open your terminal in the project directory and run the `make` command. This will use the provided `Makefile` to compile the source code and create an executable file named `reverse`.

    ```sh
    make
    ```

**Execute the program:**
Run the compiled program from your terminal, providing two arguments: the path to the input `.wav` file and the desired path for the output file.

    ```sh
    ./reverse <input.wav> <output.wav>
    ```

**Clean up object files:**
To remove the intermediate object files (`.o`) and the `reverse` executable, you can use the `clean` command.

    ```sh
    make clean
    ```
## Example Output
Input File Name: PowerupNoise.wav  
Output File Name: output.wav  
File Size: 93342  
Sample Rate: 44100  
Channels: 2  
Bits per sample: 16  
  
Starting Reversal...  
Done Reversing!  
Reversed file written to output.wav  
