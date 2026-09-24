#include "str_view.h"
#include <assert.h>

int main(void) {
    str_view sv = sv_from_cstr("hello, world!");

    const char *prefix = "hello,";
    const char *suffix = "world!";

    assert(sv_starts_with(&sv, prefix));
    assert(sv_ends_with(&sv, suffix));

    return 0;
}
