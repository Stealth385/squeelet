#include <stdio.h>
#include <stdlib.h>

#include "getline.h"
#include "repl.h"

REPL_InputBuffer* REPL_NewInputBuffer(void)
{
    REPL_InputBuffer *pInputBuffer = malloc(sizeof(REPL_InputBuffer));
    pInputBuffer->buffer = NULL;
    pInputBuffer->bufferLength = 0;
    pInputBuffer->inputLength = 0;

    return pInputBuffer;
}

void REPL_PrintPrompt(void)
{
    printf("squeelet> ");
}

void REPL_ReadInput(REPL_InputBuffer *pInputBuffer)
{
    ssize_t bytesRead = getline(&(pInputBuffer->buffer),
                                &(pInputBuffer->bufferLength),
                                stdin);
    if (bytesRead <= 0)
    {
        printf("Error reading input\r\n");
        exit(EXIT_FAILURE);
    }

    pInputBuffer->inputLength = bytesRead - 1;
    pInputBuffer->buffer[bytesRead - 1] = 0;
}
