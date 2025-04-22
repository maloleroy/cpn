#ifndef FZX_H
#define FZX_H 1

#include <stdbool.h>

#ifndef ZERO_DEGREE
    #define ZERO_DEGREE -1
#endif
#define MAX_FAST_KX_POW 63

/* A fast polynomial with integer coefficients */
typedef struct {
    int coefs[MAX_FAST_KX_POW+1];
} fZX;

typedef struct {
    int c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31, c32, c33, c34, c35, c36, c37, c38, c39, c40, c41, c42, c43, c44, c45, c46, c47, c48, c49, c50, c51, c52, c53, c54, c55, c56, c57, c58, c59, c60, c61, c62, c63;
} coefs;

fZX new_fZX(coefs l);
fZX zero_fZX(void);
bool is_zero_fZX(fZX p);

/* Returns: cn * X**n  */
fZX monomial_fZX(int n, int cn);

int coef_fZX(fZX p, int n);
bool are_equal_fZX(fZX p1, fZX p2);
int degree_fZX(fZX p);

fZX add_fZX(fZX p1, fZX p2);
fZX substract_fZX(fZX p1, fZX p2);
fZX multiply_fZX(fZX p1, fZX p2);

#endif
