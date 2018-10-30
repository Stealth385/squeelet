
typedef struct REPL_InputBuffer_t
{
    char* buffer;
    size_t bufferLength;
    ssize_t inputLength;
} REPL_InputBuffer;

REPL_InputBuffer* REPL_NewInputBuffer(void);
void REPL_PrintPrompt(void);
void REPL_ReadInput(REPL_InputBuffer *pInputBuffer);
