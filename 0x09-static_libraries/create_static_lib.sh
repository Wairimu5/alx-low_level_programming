#!/bin/bash

# Compile all .c files into .o files
gcc -c *.c

# Create the static library
ar rcs liball.a *.o

# Cleanup: remove the .o files
rm *.o

echo "Static library liball.a created successfully."
