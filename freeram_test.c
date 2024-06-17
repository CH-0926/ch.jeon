#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#define UNIT_TESTING 1
#include "freeram.c"

#define UNUSED(x) (void)(x)

long __wrap_get_free_ram(void);
long __wrap_get_free_ram(void)
{
    long free_ram = mock_type(long);
    return free_ram;
}

static void test_convert_bytes_to_kb(void **state)
{
    double result = convert_bytes(244527104, "KB");
    assert_float_equal(result, 238796.00, 0.01);
}

static void test_convert_bytes_to_mb(void **state)
{
    double result = convert_bytes(244527104, "MB");
    assert_float_equal(result, 233.20, 0.01);
}

static void test_convert_bytes_to_gb(void **state)
{
    double result = convert_bytes(244527104, "GB");
    assert_float_equal(result, 0.23, 0.01);
}


int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_convert_bytes_to_kb),
        cmocka_unit_test(test_convert_bytes_to_mb),
        cmocka_unit_test(test_convert_bytes_to_gb),
        };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
