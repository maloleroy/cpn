#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdbool.h>
#include <stdio.h>

/* Describes a rational */
typedef struct {
    int num;
    int denom;
} Q;

int abs(int a);
int gcd(int a, int b);

Q zero_Q(void);
bool is_zero_Q(Q r);
Q new_Q(int num, int denom);

Q int_to_Q(int n);
bool are_equal_Q(Q r1, Q r2);
bool is_int_Q(Q r);

Q inverse(Q r);
Q multiply_Q(Q r1, Q r2);
Q divide_Q(Q r1, Q r2);
Q add_Q(Q r1, Q r2);
Q substract_Q(Q r1, Q r2);

#endif
