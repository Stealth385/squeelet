#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "repl.h"
#include "getline.h"

int main(int argc, char* argv[])
{
    REPL_InputBuffer* inputBuffer = REPL_NewInputBuffer();
    while (true)
    {
        REPL_PrintPrompt();
        REPL_ReadInput(inputBuffer);

        if (!strcmp(inputBuffer->buffer, ".exit"))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Unrecognized command '%s'.\r\n", inputBuffer->buffer);
        }
    }

    return 0;
}
