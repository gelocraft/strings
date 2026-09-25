#include "str_view.h"
#include <assert.h>

int main(void) {
    str_view request_line = sv_from_cstr("\r\nGET / HTTP/1.1\r\n");

    assert(sv_ends_with_whitespace(&request_line));
    assert(sv_starts_with_whitespace(&request_line));

    return 0;
}
