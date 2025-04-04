#include <rational.h>

int abs(int a) {
    if (a >= 0) {
        return a;
    }
    return -a;
}

int gcd(int a, int b) {
    if (a < 0 || b < 0) {
        return gcd(abs(a), abs(b));
    }
    if (b == 0) {
        return a;
    } else if (a == 0) {
        return b;
    }
    return gcd(b, a % b);
}

Q zero_Q(void) {
    return (Q){0, 1};
}

bool is_zero_Q(Q r) {
    return r.num == 0;
}

static Q reduce(Q r) {
    if (is_zero_Q(r)) {
        return zero_Q();
    }
    int s = r.num * r.denom >= 0 ? 1 : -1;
    int d  = gcd(r.num, r.denom);
    return (Q){s * r.num / d, r.denom / d};
}


/* Creates a new rational number */
Q new_Q(int num, int denom) {
    if (denom == 0) {
        printf("Cannot fraczero\n");
    }
    return reduce((Q){num, denom});
}

Q int_to_Q(int n) {
    return new_Q(n, 1);
}

bool are_equal_Q(Q r1, Q r2) {
    return r1.num * r2.denom == r1.denom * r2.num;
}

bool is_int_Q(Q r) {
    return r.denom == 1;
}

Q inverse(Q r) {
    if (is_zero_Q(r)) {
        printf("Trying to inverse zero!\n");
        return r;
    }
    return new_Q(r.denom, r.num);
}

Q multiply_Q(Q r1, Q r2) {
    /* r1.denom != 0 and r2.denom != 0, so
     * (r1.denom*r2.denom) != 0
     */
    return reduce((Q){r1.num * r2.num, r1.denom * r2.denom});
}

Q divide_Q(Q r1, Q r2) {
    if (is_zero_Q(r2)) {
        // Error
        printf("Trying to divide %d/%d by 0\n", r1.num, r1.denom);
    }
    /* r1.denom != 0 and we checked that r2.num != 0, so
     * (r1.denom*r2.num) != 0
     */
    return reduce((Q){r1.num * r2.denom, r1.denom * r2.num});
}

Q add_Q(Q r1, Q r2) {
    /* r1.denom != 0 and r2.denom != 0, so
     * (r1.denom*r2.denom) != 0
     */
    return new_Q(r1.num * r2.denom + r2.num * r1.denom, r1.denom * r2.denom);
}

Q substract_Q(Q r1, Q r2) {
    /* r1.denom != 0 and r2.denom != 0, so
     * (r1.denom*r2.denom) != 0
     */
    return new_Q(r1.num * r2.denom - r2.num * r1.denom, r1.denom * r2.denom);
}
