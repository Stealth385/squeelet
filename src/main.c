#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "repl.h"
#include "meta_command.h"
#include "prepared_statement.h"

int main(int argc, char* argv[])
{
    REPL_InputBuffer* inputBuffer = REPL_NewInputBuffer();
    while (true)
    {
        REPL_PrintPrompt();
        REPL_ReadInput(inputBuffer);

        if (inputBuffer->buffer[0] == '.')
        {
            switch (MetaCommand_Execute(inputBuffer))
            {
            case (META_COMMAND_SUCCESS):
                continue;
            case (META_COMMAND_UNRECOGNIZED_COMMAND):
                printf("Unrecognized command '%s'.\r\n", inputBuffer->buffer);
                continue;
            }
        }

        Statement statement;
        switch(Statement_Prepare(inputBuffer, &statement))
        {
        case (PREPARE_SUCCESS):
            break;
        case (PREPARE_UNRECOGNIZED_STATEMENT):
            printf("Unrecognized keyword at start of '%s'.\r\n", inputBuffer->buffer);
            continue;
        }

        Statement_Execute(&statement);
        printf("Executed.\r\n");
    }
    return 0;
}
