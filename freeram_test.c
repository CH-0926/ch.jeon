#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#define UNIT_TESTING 1
#include "proc_freeram.h"
#include "freeram.h"

#define UNUSED(x) (void)(x)

// 모킹된 함수 정의
long __wrap_get_free_ram(void) {
    return mock_type(long);
}

static void test_convert_bytes_to_kb(void **state) {
    UNUSED(state);
    will_return(__wrap_get_free_ram, 244527104);
    long free_ram = __wrap_get_free_ram();

    double result = convert_bytes(free_ram, "KB");
    assert_float_equal(result, 238796.0, 0.01);
}

static void test_convert_bytes_to_mb(void **state) {
    UNUSED(state);
    will_return(__wrap_get_free_ram, 244527104);
    long free_ram = __wrap_get_free_ram();

    double result = convert_bytes(free_ram, "MB");
    assert_float_equal(result, 233.199219, 0.01);
}

static void test_convert_bytes_to_gb(void **state) {
    UNUSED(state);
    will_return(__wrap_get_free_ram, 244527104);
    long free_ram = __wrap_get_free_ram();

    double result = convert_bytes(free_ram, "GB");
    assert_float_equal(result, 0.227539, 0.01);
}

static void test_convert_bytes_to_tb(void **state) {
    UNUSED(state);
    will_return(__wrap_get_free_ram, 244527104);
    long free_ram = __wrap_get_free_ram();

    double result = convert_bytes(free_ram, "TB");
    assert_float_equal(result, 0.000223, 0.01);
}

// 메인 함수
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_convert_bytes_to_kb),
        cmocka_unit_test(test_convert_bytes_to_mb),
        cmocka_unit_test(test_convert_bytes_to_gb),
        cmocka_unit_test(test_convert_bytes_to_tb),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
