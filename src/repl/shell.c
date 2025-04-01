#include "shell.h"

#include<stdio.h>
#include <stdlib.h>

InputBuffer* newInputBuffer() {
    InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_lenghth = 0;

    return input_buffer;
}

// function that frees the memory allocated for an instance of InputBuffer * and the buffer element of the respective structure
// (getline allocates memory for input_buffer->buffer in read_input)
void closeInputBuffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}

// Prints a prompt to the user
// We do this beofre each line of input
void printPrompt() { printf("db > "); }

// To read a line of input using getline()
// lineptr : a pointer to the variable we use to point to the buffer containing the read line
// If it set to NULL it is mallocatted by getline and should thus be freed by the user, even if the command fails.
// n : a pointer to the variable we use to save the size of allocated buffer.
// stream : the input stream to read from. We’ll be reading from standard input.
// return value : the number of bytes read, which may be less than the size of the buffer.

// We tell getline to store the read line in input_buffer->buffer and the size of the allocated buffer in input_buffer->buffer_length
// We store the return value in input_buffer->input_length.

// buffer starts as null, so getline allocates enough memory to hold the line of input and makes buffer point to it.
void readInput(InputBuffer* input_buffer) {
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    // If we don't read any bytes print error message
    if (bytes_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    // Ignore trailing newline (empty chars at the end of line)
    input_buffer->input_lenghth = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

