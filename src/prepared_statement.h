#ifndef _PREPARED_STATEMENT_H_
#define _PREPARED_STATEMENT_H_

#include "repl.h"

typedef enum PrepareResult_t
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
} PrepareResult;

typedef enum StatementType_t
{
    STATEMENT_INSERT,
    STATEMENT_SELECT,
} StatementType;

typedef struct Statement_t
{
    StatementType type;
} Statement;

PrepareResult Statement_Prepare(REPL_InputBuffer *pInputBuffer,
                               Statement *pStatement);

void Statement_Execute(Statement *pStatement);

#endif // _PREPARED_STATEMENT_H_
