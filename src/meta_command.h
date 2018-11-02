#ifndef _META_COMMAND_H_
#define _META_COMMAND_H_

#include "repl.h"

typedef enum MetaCommandResult_t
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
} MetaCommandResult;

MetaCommandResult MetaCommand_Execute(REPL_InputBuffer *pInput);

#endif // _META_COMMAND_H_
