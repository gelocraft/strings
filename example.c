#include "str_builder.h"
#include <assert.h>

int main(void) {
    str_builder request = sb_new();
    sb_append_cstr(&request, "GET / HTTP/1.1\r\n");
    sb_append_cstr(&request, "Host: localhost:6969\r\n");
    sb_append_cstr(&request, "User-Agent: curl/8.22.0\r\n");
    sb_append_cstr(&request, "Accept: */*\r\n");
    sb_append_cstr(&request, "\r\n");

    sb_print(request);

    sb_reset(&request);
    sb_reset(&request);
    sb_reset(&request);

    fprintf(stdout, "after reset: [");
    sb_print(request);
    putchar(']');
    putchar('\n');

    sb_free(&request);

    fprintf(stdout, "after free: [");
    sb_print(request);
    putchar(']');
}
