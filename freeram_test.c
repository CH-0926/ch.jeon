#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#define UNIT_TESTING 1
#include "proc_freeram.h"
#include "freeram.c"

#define UNUSED(x) (void)(x)

// 모킹된 함수 정의
long __wrap_get_free_ram(const char *meminfo_path) {
    UNUSED(meminfo_path);
    check_expected_ptr(meminfo_path);

    return mock_type(long);
}

//Unit test convert_bytes
static void test_convert_bytes(void **state) {
    
    char *result = NULL;

    UNUSED(state);

    expect_string(__wrap_get_free_ram, meminfo_path,"/proc/meminfo");
    will_return(__wrap_get_free_ram, 238796);
    
    result = convert_bytes();
    const char *expected_output =
        "Freeram: 244527104.00 bytes\n"
        "Freeram: 238796.00 KB\n"
        "Freeram: 233.20 MB\n"
        "Freeram: 0.23 GB\n"
        "Freeram: 0.00 TB\n";

    assert_non_null(result);
    assert_string_equal(result, expected_output);

    free(result);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_convert_bytes),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
