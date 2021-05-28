#include "../include/util.h"

char* read_file(const char* path)
{
    // Open File
    FILE *file = fopen(path, "r");
    if (!file)
    {
        printf("Could not read file '%s'\n", path);
        return NULL;
    }

    // Get size of file
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate the size of the file + 1
    char* buf = (char*) malloc(sizeof(char) * (size + 1));
    if (!buf)
    {
        printf("Could not allocate memory for file!\n");
        return NULL;
    }
    // Read file
    fread(buf, 1, size, file);
    buf[size] = "\0";
    fclose(file);

    // Return contents
    return buf;
}
