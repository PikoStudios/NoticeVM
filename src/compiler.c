#include "../include/compiler.h"

void compiler_start(Compiler* c)
{
    c->bytecode = byte_buffer_create(1);

    for (int i = 0; i < c->tokens->ptr; i++)
    {
        Token* t = token_list_get(c->tokens, i);

        if (t->type == INST)
        {
            switch (t->data)
            {
            case PUSH:
                // PUSH #N
                if (token_list_get(c->tokens, i + 1)->type == NUMBER)
                {
                    bb_write8(c->bytecode, PUSH_CONST);
                    bb_write32(c->bytecode, token_list_get(c->tokens, i + 1)->data);
#ifdef DEBUG
                    printf("index: %i, value: %i\n", i, token_list_get(c->tokens, i + 1)->data);
#endif
                    i++;
                    
                }
                else
                {
                    printf("Bad Push Instruction, Missing Data\n");
                    c->status = COMPILER_ERROR;
                    return;
                }
                break;
            
            case ADD:
                bb_write8(c->bytecode, ADD_STACK);
                break;

            case HLT:
                bb_write8(c->bytecode, HLT_OP);

            default:
                bb_write8(c->bytecode, NOP);
            }
        }
    }
    c->status = COMPILER_SCCESS;
}