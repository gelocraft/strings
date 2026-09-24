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

bool sv_ends_with(str_view *sv, const char *suffix) {
    size_t sv_len = sv->len;
    size_t suffix_len = strlen(suffix);

    if (suffix_len > sv_len) {
        return false;
    }

    for (size_t i = suffix_len; i > 0; i--) {
        if (sv->data[sv_len - 1] != suffix[i - 1]) {
            return false;
        }
        sv_len--;
    }

    return true;
}

bool sv_starts_with(str_view *sv, const char *prefix) {
    size_t prefix_len = strlen(prefix);
    if (prefix_len > sv->len) {
        return false;
    }

    for (size_t i = 0; i < prefix_len; i++) {
        if (sv->data[i] != prefix[i]) {
            return false;
        }
    }
    return true;
}

str_view sv_chop_by_delim(str_view *sv, const char delim) {
    size_t i = 0;
    for (; i < sv->len; i++) {
        if (delim == sv->data[i])
            break;
    }
    ++i;

    str_view chopped = {
        .data = sv->data,
        .len = sv->len > i ? i - 1 : sv->len,
    };

    if (sv->len > i) {
        sv->data += i;
        sv->len -= i;
    }

    return chopped;
}
