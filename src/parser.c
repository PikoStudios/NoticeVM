#include "../include/parser.h"

ParserStatus parser_start(TokenList* list, const char* source)
{
    char lex[256];
    int lexi = 0;
    int i = 0;
    int line = 1;
    while (1)
    {
        //memset(lex, 0, 256);

        while (source[i] != ' ' && source[i] != '\n' && source[i] != '\0')
        {
            lex[lexi++] = source[i++];
        }
        lex[lexi] = '\0';
        
        
        if (lex[0] == '\0') break;
        if (lex[0] == '\r') break;
        // TODO: care more about empty lines
        // TODO: care about tabs
        

        // This is a numerical constant
        if (lex[0] == '#')
        {
            int num = parser_get_number(lex);
#ifdef DEBUG
            printf("UINT_32: Line %i, Value: %i\n", line, num);
#endif
            token_list_add(list, token_create(NUMBER, num, line));
            
        }

        // Must be an instruction
        else
        {
            int inst = parser_get_inst(lex);
            if (inst >= 0)
            {
                token_list_add(list, token_create(INST, inst, line));
#ifdef DEBUG
                printf("INSTRUCTION: Line: %i, Value: %s\n", line, lex);
#endif
            }
            else 
            {
                printf("Syntax Error: Line %i: Invalid Instruction '%s'", line, lex);
                return PARSER_SYNTAX_ERROR;
            }
            
        }

        // New Line
        if (source[i] == '\n') 
        {
            line++;
#ifdef DEBUG
            printf("Reached New line\n");
#endif
        }
        else if (source[i] == '\0')
        {
#ifdef DEBUG
            printf("Reached end of file");
#endif
            break;
        }
        // else if (source[i] == -1) break; <-- possible fix on WSL

        lexi = 0;
        i++;
    }
    
        
    return PARSER_SUCCESS;

}

uint32_t parser_get_number(const char* buf)
{
    long num = atoi(&buf[1]);
    return (num <= UINT32_MAX) ? num : 0;
}

TokenInst parser_get_inst(const char* buf)
{
    if (strcmp(buf, "push") == 0) return PUSH;
    if (strcmp(buf, "add") == 0) return ADD;
    if (strcmp(buf, "hlt") == 0) return HLT;
    return (TokenInst)-1;
}