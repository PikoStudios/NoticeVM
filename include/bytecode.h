#ifndef NOTICE_BYTECODE_H
#define NOTICE_BYTECODE_H

enum _Opcode 
{
    NOP = 0x00,
    PUSH_CONST = 0x01,
    ADD_STACK = 0x02,
    HLT_OP = 0xFF
};

#endif // NOTICE_BYTECODE_H