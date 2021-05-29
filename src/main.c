#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"
#include "../include/token.h"
#include "../include/parser.h"

// notice compile file.nto

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("NoticeVM :: Too few arguments\n");
        return 1;
    }

    if (strcmp(argv[1], "compile") == 0)
    {
        char* source = read_file(argv[2]);
        TokenList tokens;
        init_token_list(&tokens, 1);
        ParserStatus pstat = parser_start(&tokens, source);
        if (pstat != PARSER_SUCCESS)
            return 1;

        for (int i = 0; i < tokens.ptr; i++)
        {
            Token* t = token_list_get(&tokens, i);
            printf("%d, %d, %d\n", t->type, t->data, t->line);
        }


        free(source);
    }

    

    return 0;
}