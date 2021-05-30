#ifndef NOTICE_COMPILER_H
#define NOTICE_COMPILER_H

#include <stdio.h>

#include "token.h"
#include "bytebuffer.h"
#include "bytecode.h"

enum _CompilerStatus
{
    COMPILER_SCCESS,
    COMPILER_ERROR
};

typedef enum _CompilerStatus CompilerStatus;

struct _Compiler
{
    CompilerStatus status;
    TokenList* tokens;
    ByteBuffer* bytecode;
};

typedef struct _Compiler Compiler;

void compiler_start(Compiler* c);

#endif // NOTICE_COMPILER_H