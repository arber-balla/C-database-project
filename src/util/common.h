#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

// Wrapper around the state we need to store to interact with geline().
typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_lenghth;
} InputBuffer;


//! Function declaration
// Generates the input buffer
InputBuffer* newInputBuffer();

// Close the input buffer
void closeInputBuffer(InputBuffer* imput_buffer);

#endif
