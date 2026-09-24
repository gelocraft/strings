#ifndef STR_VIEW_H
#define STR_VIEW_H

#include <stddef.h>

typedef struct {
    const char* data;
    size_t len;
} str_view;

str_view sv_from_cstr(const char *cstr);

void sv_print(str_view *sv);

void sv_trim(str_view *sv);
void sv_trim_end(str_view *sv);
void sv_trim_start(str_view *sv);

#endif // !STR_VIEW_H
