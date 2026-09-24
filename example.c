#include "str_view.h"
int main(void) {
    str_view sv = sv_from_cstr("    hello, world!   ");
    sv_trim(&sv);
    sv_print(&sv);

    return 0;
}
