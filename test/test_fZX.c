#include <confer.h>
#include <fZX.h>

#define assert_fZX_equal(p, q) assert_chain(are_equal_fZX, p, q)
#define assert_fZX_not_equal(p, q) assert_chain_not(are_equal_fZX, p, q)

static void test_zero_fZX(CFTEST);
static void test_coef_fZX(CFTEST);
static void test_degree_fZX(CFTEST);
static void test_are_equal_fZX(CFTEST);
static void test_add_fZX(CFTEST);
static void test_multiply_fZX(CFTEST);
static void test_monomial_fZX(CFTEST);


void test_fZX(CFTEST) {
    cf_test(test_zero_fZX);
    cf_test(test_coef_fZX);
    cf_test(test_degree_fZX);
    cf_test(test_are_equal_fZX);
    cf_test(test_add_fZX);
    cf_test(test_multiply_fZX);
    cf_test(test_monomial_fZX);
}

static void test_zero_fZX(CFTEST) {
    fZX zero = zero_fZX();
    for (int i = 0; i <= MAX_FAST_KX_POW; i++) {
        assert_int_equal(coef_fZX(zero, i), 0);
    }
}

static void test_coef_fZX(CFTEST) {
    fZX p = new_fZX((coefs){.c2 = -3, .c0 = 7});
    assert_int_equal(coef_fZX(p, 2022), 0);
    assert_int_equal(coef_fZX(p, 2), -3);
}

static void test_degree_fZX(CFTEST) {
    fZX zero = zero_fZX();
    fZX p = new_fZX((coefs){.c2 = -3, .c0 = 7});
    fZX q = new_fZX((coefs){.c5 = 1, .c2 = -4, .c0 = 1});
    assert_int_equal(degree_fZX(zero), ZERO_DEGREE);
    assert_int_equal(degree_fZX(p), 2);
    assert_int_equal(degree_fZX(q), 5);
}

static void test_are_equal_fZX(CFTEST) {
    fZX zero = zero_fZX();
    fZX p = new_fZX((coefs){.c2 = -3, .c0 = 7});
    fZX q = new_fZX((coefs){.c5 = 1, .c2 = -4, .c0 = 1});
    assert_true(are_equal_fZX(p, p));
    assert_true(are_equal_fZX(q, q));
    assert_false(are_equal_fZX(p, q));
    assert_false(are_equal_fZX(q, p));
    assert_false(are_equal_fZX(zero, p));
    assert_false(are_equal_fZX(p, zero));
}

static void test_add_fZX(CFTEST) {
    fZX zero = zero_fZX();
    fZX p = new_fZX((coefs){.c2 = -3, .c0 = 7});
    fZX q = new_fZX((coefs){.c5 = 1, .c2 = -4, .c0 = 1});
    fZX p_plus_q = new_fZX((coefs){.c5 = 1, .c2 = -7, .c0 = 8});
    assert_true(are_equal_fZX(add_fZX(p, q), p_plus_q));
    assert_true(are_equal_fZX(add_fZX(q, p), p_plus_q));

    assert_true(are_equal_fZX(add_fZX(p, zero), p));
    assert_true(are_equal_fZX(add_fZX(zero, p), p));
}

static void test_multiply_fZX(CFTEST) {
    fZX p = new_fZX((coefs){.c2 = -3, .c0 = 7});
    fZX q = new_fZX((coefs){.c5 = 1, .c2 = -4, .c0 = 1});
    fZX pq = new_fZX((coefs){.c7 = -3, .c5 = 7, .c4 = 12, .c2 = -31, .c0 = 7});
    assert_true(are_equal_fZX(multiply_fZX(p, q), pq));
}

static void test_monomial_fZX(CFTEST) {
    assert_true(are_equal_fZX(monomial_fZX(0, 13), new_fZX((coefs){.c0 = 13})));
    assert_true(are_equal_fZX(monomial_fZX(12, 2), new_fZX((coefs){.c12 = 2})));
}
