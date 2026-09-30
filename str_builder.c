#include "str_builder.h"
#include <stdlib.h>
#include <string.h>

str_builder sb_from_cstr(const char *cstr) {
    size_t cstr_len = strlen(cstr);
    size_t capacity = DEFAULT_CAPACITY;

    while (capacity <= cstr_len) capacity *= 2;

    char *data = malloc(sizeof(char) * capacity);

    return (str_builder){
        .data = strcpy(data, cstr),
        .capacity = capacity,
        .len = cstr_len,
    };
}

void sb_free(str_builder *sb) {
    free(sb->data);
    sb->data = NULL;
    sb->len = 0;
    sb->capacity = 0;
}

void sb_reset(str_builder *sb) {
    if (sb->len == 0 && sb->capacity == DEFAULT_CAPACITY) return;

    memset(sb->data, 0, sizeof(char) * sb->capacity);
    void *ptr = realloc(sb->data, sizeof(char) * DEFAULT_CAPACITY);
    if (ptr == NULL) {
        perror("realloc");
        exit(1);
    }

    sb->len = 0;
    sb->data = ptr;
    sb->capacity = DEFAULT_CAPACITY;
}

void sb_print(str_builder sb) { fprintf(stdout, "%s", sb.data); }

void sb_append_cstr(str_builder *sb, const char *cstr) {
    size_t cstr_len = strlen(cstr);
    size_t capacity = sb->capacity;

    if (capacity <= (cstr_len + sb->len)) {
        while (capacity <= (cstr_len + sb->len)) capacity *= 2;
        void *ptr = realloc(sb->data, sizeof(char) * capacity);
        if (ptr == NULL) {
            perror("realloc");
            exit(1);
        }
        sb->data = ptr;
    }

    sb->len += cstr_len;
    sb->capacity = capacity;
    sb->data = strcat(sb->data, cstr);
}
