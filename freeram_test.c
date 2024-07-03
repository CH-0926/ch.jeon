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
long __wrap_get_free_ram(void) {
    return mock_type(long);
}

static void assert_convert_bytes(long bytes, const char *unit, double expected, double tolerance) {
    double result = convert_bytes(bytes, unit);
    assert_float_equal(result, expected, tolerance);
}

//Unit test get_free_ram
static void test_get_free_ram(void **state) {
    UNUSED(state);

    will_return(__wrap_get_free_ram, 244527104);
    long free_ram = __wrap_get_free_ram();

    assert_int_equal(free_ram, 244527104);
}
//Unit test convert_bytes
static void test_convert_bytes(void **state) {
    UNUSED(state);
    will_return(__wrap_get_free_ram, 244527104);
    long free_ram = __wrap_get_free_ram();

    assert_convert_bytes(free_ram, "KB", 238796.0, 0.01);
    assert_convert_bytes(free_ram, "MB", 233.199219, 0.01);
    assert_convert_bytes(free_ram, "GB", 0.227539, 0.01);
    assert_convert_bytes(free_ram, "TB", 0.000223, 0.01);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_get_free_ram),
        cmocka_unit_test(test_convert_bytes),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
