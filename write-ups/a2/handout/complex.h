#ifndef _COMPLEX_H_
#define _COMPLEX_H_

struct complex
{
  double real;
  double imaginary;
};

struct complex complex_add(struct complex a, struct complex b);

struct complex complex_subtract(struct complex a, struct complex b);

struct complex complex_multiply(struct complex a, struct complex b);

struct complex complex_divide(struct complex a, struct complex b);

#endif
