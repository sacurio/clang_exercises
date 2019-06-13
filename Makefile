# Default compiler for C program: gcc
# The compiler can be changed throught CC variable in use with
# make command. make-command CC=new_value -optional-flags
# example: make CC=clang all
CC=gcc 

# Compiler flags
CFLAGS = -g -Wall -fno-stack-protector

# the build taget executable
TARGET=array

# build the target executable
all : $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

# clean binary files
clean :
	$(RM) $(TARGET)