#include "str_view.h"
#include <assert.h>

int main(void) {
    str_view raw_http_request =
        sv_from_cstr("GET / HTTP/1.1\r\nHost: localhost:6969\r\n");

    str_view request_line = sv_chop_by_crlf(&raw_http_request);
    str_view field_line = sv_chop_by_crlf(&raw_http_request);
    str_view empty_line = sv_chop_by_crlf(&raw_http_request);

    assert(sv_equal_cstr(request_line, "GET / HTTP/1.1\r\n"));
    assert(sv_equal_cstr(field_line, "Host: localhost:6969\r\n"));

    assert(sv_ends_with_crlf(request_line));
    assert(sv_ends_with_crlf(field_line));

    assert(sv_empty(empty_line));
}
