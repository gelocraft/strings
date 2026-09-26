#ifndef STR_VIEW_H
#define STR_VIEW_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    const char* data;
    size_t len;
} str_view;

str_view sv_from_cstr(const char *cstr);

void sv_print(str_view *sv);

void sv_trim(str_view *sv);
void sv_trim_end(str_view *sv);
void sv_trim_start(str_view *sv);

bool sv_ends_with(str_view *sv, const char *suffix);
bool sv_starts_with(str_view *sv, const char *prefix);

bool sv_ends_with_whitespace(str_view *sv);
bool sv_starts_with_whitespace(str_view *sv);

str_view sv_chop_by_delim(str_view *sv, const char delim);

str_view sv_identity(str_view *sv);

bool sv_equal(str_view *sv1, str_view *sv2);
bool sv_equal_cstr(str_view *sv, const char *cstr);

#endif // !STR_VIEW_H
