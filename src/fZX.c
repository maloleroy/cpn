#include <fZX.h>

fZX new_fZX(coefs l) {
    return (fZX){{l.c0, l.c1, l.c2, l.c3, l.c4, l.c5, l.c6, l.c7, l.c8, l.c9, l.c10, l.c11, l.c12, l.c13, l.c14, l.c15, l.c16, l.c17, l.c18, l.c19, l.c20, l.c21, l.c22, l.c23, l.c24, l.c25, l.c26, l.c27, l.c28, l.c29, l.c30, l.c31, l.c32, l.c33, l.c34, l.c35, l.c36, l.c37, l.c38, l.c39, l.c40, l.c41, l.c42, l.c43, l.c44, l.c45, l.c46, l.c47, l.c48, l.c49, l.c50, l.c51, l.c52, l.c53, l.c54, l.c55, l.c56, l.c57, l.c58, l.c59, l.c60, l.c61, l.c62, l.c63}};
}

fZX zero_fZX(void) {
    return new_fZX((coefs){.c0 = 0});
}

bool is_zero_fZX(fZX p) {
    return degree_fZX(p) == ZERO_DEGREE;
}

fZX monomial_fZX(int n, int cn) {
    if (n < 0 || n > MAX_FAST_KX_POW) {
        // Error
    }
    fZX r = zero_fZX();
    r.coefs[n] = cn;
    return r;
}

int coef_fZX(fZX p, int n) {
    if (n > MAX_FAST_KX_POW || n < 0) {
        return 0;
    }
    return p.coefs[n];
}

bool are_equal_fZX(fZX p1, fZX p2) {
    for (int i = 0; i <= MAX_FAST_KX_POW; i++) {
        if (coef_fZX(p1, i) != coef_fZX(p2, i)) {
            return false;
        }
    }
    return true;
}


int degree_fZX(fZX p) {
    for (int i = MAX_FAST_KX_POW; i >= 0; i--) {
        if (coef_fZX(p, i) != 0) {
            return i;
        }
    }
    return ZERO_DEGREE;
}

fZX add_fZX(fZX p1, fZX p2) {
    fZX r = zero_fZX();
    for (int i = 0; i <= MAX_FAST_KX_POW; i++) {
        r.coefs[i]  = coef_fZX(p1, i) + coef_fZX(p2, i);
    }
    return r;
}

fZX substract_fZX(fZX p1, fZX p2) {
    fZX r = zero_fZX();
    for (int i = 0; i <= MAX_FAST_KX_POW; i++) {
        r.coefs[i]  = coef_fZX(p1, i) - coef_fZX(p2, i);
    }
    return r;
}

fZX multiply_fZX(fZX p1, fZX p2) {
    if (degree_fZX(p1) + degree_fZX(p2) > MAX_FAST_KX_POW) {
        // Error
    }
    fZX r = zero_fZX();
    for (int k = 0; k <= MAX_FAST_KX_POW; k++) {
        for (int i = 0; i <= k; i++) {
            r.coefs[k] += p1.coefs[i] *  p2.coefs[k-i];
        }
    }
    return r;
}
