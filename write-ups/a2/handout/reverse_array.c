#include <stdio.h>  // needed for the definition of NULL, printf
#include <stdint.h> // needed for the definition of uint32_t
#include <assert.h> // needed for the definition of assert()

void reverse_array(uint32_t *arr, unsigned int len)
{
  // sanity check
  assert(arr != NULL);
  // reverse
  for (int i = 0; i < (len / 2); i++)
  {
    uint32_t tmp = arr[i];
    arr[i] = arr[len - 1 - i];
    arr[len - 1 - i] = tmp;
  }
}

void print_array(uint32_t *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%u ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  // test
  uint32_t arr[3] = {1, 2, 3};
  print_array(arr, 3);
  reverse_array(arr, 3);
  print_array(arr, 3);
  return 0;
}
