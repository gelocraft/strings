#include "str_view.h"
#include <assert.h>

int main(void) {
    str_view request_line = sv_from_cstr("GET / HTTP/1.1");

    str_view method = sv_chop_by_delim(&request_line, ' ');
    str_view target = sv_chop_by_delim(&request_line, ' ');
    str_view http_version = sv_chop_by_delim(&request_line, ' ');

    if (http_version.data == NULL) http_version = request_line;

    sv_print(&method);
    sv_print(&target);
    sv_print(&http_version);

    return 0;
}
