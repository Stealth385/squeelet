#include <stdlib.h>
#include <string.h>
#include "meta_command.h"

MetaCommandResult MetaCommand_Execute(REPL_InputBuffer *pInput)
{
    if (!strcmp(pInput->buffer, ".exit"))
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
