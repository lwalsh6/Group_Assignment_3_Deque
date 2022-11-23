# Logan Walsh/Zachary Rose
# 11-23-2022
# Makefile
# Makefile Test Program for compiling the deque program
# Typing "make" compiles the program

# Variables are defined for the compiler and compiler flag
# These variables can be used with $()

CC = g++
CFLAGS = -g -Wall -Wextra

# Set to compile when "Make" is called
# Set to be the default entry

default: deque

# List the object files needed to create the executable file.
# Compile with all errors and warnings
deque:			deque.o main.o
			$(CC) $(CFlags) -o deque deque.o main.o

# A list of object files needed to create the executable file.
deque.o:	deque.cpp deque.h
# Compile deque.o with all errors and warnings
		$(CC) $(CFLAGS) -c deque.cpp

main.o:		main.cpp deque.h
# Compile main.o with all errors and warnings
		$(CC) $(CFLAGS) -c main.cpp

#This names the "executable" for the program. After compiling type ./deque
clean:
	$(RM) deque *.o *~
