#ifndef META_H
#define META_H

#include "util/common.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

//! Function decalaration
// Meta command execution function
MetaCommandResult doMetaCommand(InputBuffer* input_buffer);
#endif
