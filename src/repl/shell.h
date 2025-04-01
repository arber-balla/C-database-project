#ifndef SHELL_H
#define SHELL_H

#include "util/common.h"

//! Function decalaration
// Prints a prompt to the user
void printPrompt();

// Read a line of input
void readInput(InputBuffer* input_buffer);

#endif
