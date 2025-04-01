#ifndef TABLE_H
#define TABLE_H

#include "util/common.h"
typedef enum { PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

typedef enum { STATEMENT_INSERT,
    STATEMENT_SELECT } StatementType;

typedef struct {
StatementType type;
} Statement;

//! Function decalaration
PrepareResult prepareStatement(InputBuffer* input_buffer, Statement* statement);
void executeStatement(Statement* statement);

#endif
