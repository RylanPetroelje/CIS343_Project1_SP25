# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = reverse

# Source and object files
SRCS = original_main.c file_lib.c wav.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation
%.o: %.c file_lib.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)