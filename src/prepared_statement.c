#include <stdio.h>
#include <string.h>

#include "prepared_statement.h"

PrepareResult Statement_Prepare(REPL_InputBuffer *pInputBuffer, Statement *pStatement)
{
    if (!strncmp(pInputBuffer->buffer, "insert", 6))
    {
        pStatement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (!strcmp(pInputBuffer->buffer, "select"))
    {
        pStatement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void Statement_Execute(Statement *pStatement)
{
    switch (pStatement->type)
    {
    case (STATEMENT_INSERT):
        printf("This is where we would do an insert.\r\n");
        break;
    case (STATEMENT_SELECT):
        printf("This is where we would do a select.\r\n");
        break;
    }
}
