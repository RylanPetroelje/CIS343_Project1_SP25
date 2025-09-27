#compile flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = reverse

SRCS = main.c file_lib.c wav.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#compile
%.o: %.c file_lib.h
	$(CC) $(CFLAGS) -c $< -o $@

#get rid of .o's
clean:
	rm -f $(OBJS) $(TARGET)