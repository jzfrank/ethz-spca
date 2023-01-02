#include <stdio.h>  // needed for printf()
#include <assert.h> // needed for assert()
#include <stdlib.h> // needed for malloc()

struct complex
{
  double real; // real component
  double imag; // imaginary component
};

struct complex_set
{
  int num_points_in_set;
  struct complex *points; // an array of Complex
};

// here are the prototypes we need to implement
struct complex_set *alloc_set(struct complex c_arr[], int size);
void free_set(struct complex_set *set);

int main(int argc, char **argv)
{
  struct complex arr[5];
  struct complex_set *x;

  x = alloc_set(arr, 5);
  assert(x->num_points_in_set == 5);
  free_set(x);
  x = NULL;

  return 0;
}

struct complex_set *alloc_set(struct complex c_arr[], int size)
{
  struct complex_set *new_set = malloc(sizeof(struct complex_set));
  // check if malloc succeeded
  if (new_set == NULL)
  {
    return NULL;
  }

  struct complex *points_array = malloc(sizeof(struct complex) * size);
  if (points_array == NULL)
  {
    free(new_set);
    return NULL;
  }

  // initialize new_set
  for (int i = 0; i < size; i++)
  {
    *(points_array + i) = c_arr[i];
  }
  new_set->points = points_array;
  new_set->num_points_in_set = size;
  return new_set;
}

void free_set(struct complex_set *set)
{
  // sanity check
  assert(set != NULL);
  assert(set->points != NULL);

  free(set->points);
  set->points = NULL; // set it to NULL after free
  free(set);
}