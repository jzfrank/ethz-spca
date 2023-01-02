#include "complex.h"

struct complex complex_add(struct complex a, struct complex b)
{
  struct complex res;

  res.real = a.real + b.real;
  res.imaginary = a.imaginary + b.imaginary;
  return res;
}

struct complex complex_subtract(struct complex a, struct complex b)
{
  struct complex res;

  res.real = a.real - b.real;
  res.imaginary = a.imaginary - b.imaginary;
  return res;
}

struct complex complex_multiply(struct complex a, struct complex b)
{
  struct complex res;

  res.real = a.real * b.real - a.imaginary * b.imaginary;
  res.imaginary = a.real * b.imaginary + a.imaginary * b.real;
  return res;
}

struct complex complex_divide(struct complex a, struct complex b)
{
  struct complex res;

  double denom = b.real * b.real + b.imaginary * b.imaginary;

  b.imaginary = -b.imaginary;
  struct complex tmp = complex_multiply(a, b);
  b.imaginary = -b.imaginary;
  res.real = tmp.real / denom;
  res.imaginary = tmp.imaginary / denom;
  return res;
}