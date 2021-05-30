#ifndef NOTICE_UTIL_H
#define NOTICE_UTIL_H

#include <stdlib.h>
#include <stdio.h>

#include "bytebuffer.h"

char* read_file(const char* path);
void write_binary_file(const char* path, ByteBuffer* bb);

#endif // NOTICE_UTIL_H