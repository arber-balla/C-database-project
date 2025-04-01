#include "meta.h"
#include <stdlib.h>

// Non-SQL statements like ".exit" are called “meta-commands”
// They all start with a dot, so we check for them and handle them in a separate function.
// doMetaCommands is a wrapper for existing functionality that leaves room for more commands:
// Returns enum indicating success or failure
MetaCommandResult doMetaCommand(InputBuffer* input_buffer) {
    // if ".exit" meta-command
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        closeInputBuffer(input_buffer);
        exit(EXIT_SUCCESS);
    } else {  // If non valid meta-command
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
