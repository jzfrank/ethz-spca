#include <stdio.h>

void check_endian()
{
  // https://stackoverflow.com/questions/12791864/c-program-to-check-little-vs-big-endian/12792301#12792301
  int x = 1; // 4 bytes
  char *charptr = (char *)&x;

  printf("size of int: %lu \n", sizeof(int));
  for (int i = 0; i < 4; i++)
  {
    printf("%u ", charptr[i]);
  }
  printf("\n");

  if (*charptr == 1)
    printf("little endian\n");
  else
    printf("big endian\n");
}

int main(int argc, char **argv)
{
  check_endian();
}