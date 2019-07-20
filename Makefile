# Default compiler for C program: gcc
# The compiler can be changed throught CC variable in use with
# make command. make-command CC=new_value -optional-flags
# example: make CC=clang all
CC=gcc

# Compiler flags
CFLAGS = -g -Wall -fno-stack-protector

# the build taget executable
TARGET=darray
INCLUDES=include/*.c

# build the target executable
all : $(TARGET)
	@echo " > Building solution..."
$(TARGET): $(TARGET).c
	echo $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(INCLUDES)

# clean binary files
clean :
	@echo " > Cleaning solution..."
	$(RM) $(TARGET)
run: clean all
	@echo " > Running solution..."
	 ./$(TARGET)