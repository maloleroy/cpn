#include <stdbool.h>
#include <confer.h>

#include <rational.h>

void test_integers(CFTEST);
void test_Q(CFTEST);
void test_operations(CFTEST);

void test_rational(CFTEST) {
    cfTest(test_integers);
    cfTest(test_Q);
    cfTest(test_operations);
}

void test_integers(CFTEST) {
    // abs
    assertIntEqual(abs(3), 3);
    assertIntEqual(abs(-3), 3);

    // gcd
    assertIntEqual(gcd(15, 7), 1);
    assertIntEqual(gcd(12, 18), 6);
}

void test_Q(CFTEST) {
    Q one_half =  new_Q(1, 2);
    Q two_thirds = new_Q(2, 3);

    // is_zero_Q
    assertTrue(is_zero_Q(new_Q(0, 1)));
    assertFalse(is_zero_Q(one_half));

    // zero_Q
    assertTrue(is_zero_Q(zero_Q()));

    // are_equal_Q
    assertTrue(are_equal_Q(one_half, new_Q(8, 16)));
    assertFalse(are_equal_Q(one_half, two_thirds));

    // is_int
    assertTrue(is_int_Q(new_Q(6, 3)));
    assertFalse(is_int_Q(one_half));
    assertTrue(is_int_Q(zero_Q()));
}

void test_operations(CFTEST) {
    Q a = new_Q(3, 4);
    Q b = new_Q(27, 5);
    Q a_plus_b = new_Q(123, 20);
    Q a_minus_b = new_Q(-93, 20);

    // * and /
    // assertTrue(are_equal_Q());

    // + and -
    assertTrue(are_equal_Q(add_Q(a, b), a_plus_b));
    assertTrue(are_equal_Q(substract_Q(a, b), a_minus_b));
}
