#include "str_view.h"
#include <assert.h>

int main(void) {
    str_view request_line = sv_from_cstr("GET / HTTP/1.1\r\n");
    sv_trim_end(&request_line);

    str_view method = sv_chop_by_delim(&request_line, ' ');
    str_view target = sv_chop_by_delim(&request_line, ' ');
    str_view http_version = sv_identity(&request_line);

    assert(sv_equal(&request_line, &http_version));

    assert(sv_equal_cstr(&method, "GET"));
    assert(sv_equal_cstr(&target, "/"));
    assert(sv_equal_cstr(&http_version, "HTTP/1.1"));

    return 0;
}
