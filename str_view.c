#include "str_view.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

str_view sv_from_cstr(const char *cstr) {
    return (str_view){
        .data = cstr,
        .len = strlen(cstr),
    };
}

void sv_print(str_view *sv) {
    size_t i = 0;
    putchar('|');
    for (; i < sv->len; i++) {
        putchar(sv->data[i]);
    }
    puts("|");
}

void sv_trim(str_view *sv) {
    sv_trim_start(sv);
    sv_trim_end(sv);
}

void sv_trim_end(str_view *sv) {
    while (sv->len > 0 && isspace(sv->data[sv->len - 1]))
        sv->len--;
}

void sv_trim_start(str_view *sv) {
    while (sv->len > 0 && isspace(sv->data[0])) {
        sv->data += 1;
        sv->len -= 1;
    }
}
