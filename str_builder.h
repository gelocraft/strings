#ifndef STR_BUILDER_H
#define STR_BUILDER_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 5

typedef struct {
    char *data;
    size_t capacity;
    size_t len;
} str_builder;

str_builder sb_from_cstr(const char *cstr);
void sb_free(str_builder *sb);
void sb_reset(str_builder *sb);
void sb_print(str_builder sb);
void sb_append_cstr(str_builder *sb, const char *cstr);


#endif // !STR_BUILDER_H
