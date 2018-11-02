#ifndef _REPL_H_
#define _REPL_H_

#include <sys/types.h>
#include <stddef.h>

typedef struct REPL_InputBuffer_t
{
    char* buffer;
    size_t bufferLength;
    ssize_t inputLength;
} REPL_InputBuffer;

REPL_InputBuffer* REPL_NewInputBuffer(void);
void REPL_PrintPrompt(void);
void REPL_ReadInput(REPL_InputBuffer *pInputBuffer);

#endif // _REPL_H_
