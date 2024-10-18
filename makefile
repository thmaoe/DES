# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic

# Target executable
TARGET = des

# Source and object files
SRCS = DES.c DES_algos.c DES_keys.c DES_utils.c constants.c
OBJS = $(SRCS:.c=.o)

# Rule to build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: des
	./des

# Clean up the directory (remove executable and object files)
clean:
	rm -f $(TARGET) $(OBJS)
