#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"

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
        printf("%s\n", source);
        free(source);
    }

    

    return 0;
}