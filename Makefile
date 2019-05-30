#make file

# the compiler: gcc for C program
CC=gcc 

# the build taget executable
TARGET=array

# build the target executable
all : $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) -g -fno-stack-protector -o $(TARGET) $(TARGET).c

# clean binary files
clean :
	$(RM) $(TARGET)