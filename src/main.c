#include <stdbool.h>
#include <stdio.h>

#include "repl/shell.h"
#include "meta/meta.h"
#include "storage/pages.h"
#include "table/table.h"
#include "util/common.h"


int main(int argc, char* argv[]) {
    InputBuffer* input_buffer = newInputBuffer();

    // SQL starts a read-execute-print loop when you start the command line
    // To do that ou main function will have an infinite loop that:
    // 1) prints the prompt
    // 2) get an input
    // 3) processes that line of input
    while (true) {
        printPrompt();
        readInput(input_buffer);

        // if command starts with "."
        if (input_buffer->buffer[0] == '.') {
            switch (doMetaCommand(input_buffer)) {
                case (META_COMMAND_SUCCESS):  // If valid meta-command
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):                         // If invalid meta-command
                    printf("Unrecognized command '%s'\n", input_buffer->buffer);  // Print error message
                    continue;
            }
        }

        Statement statement;  // Statement declaration
        switch (prepareStatement(input_buffer, &statement)) {
            case (PREPARE_SUCCESS):  // If valid statement
                break;
            case (PREPARE_UNRECOGNIZED_STATEMENT):                                         // If unvalid statement
                printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);  // Print error message
                continue;
        }

        // If command processin succeds execute the command
        executeStatement(&statement);
        printf("Executed.\n");  // Print success message
    }
}
