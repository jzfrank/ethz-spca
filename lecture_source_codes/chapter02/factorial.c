/* Compute factorial function */
/* fact(n) = n * (n-1) * ... * 2 * 1 */

#include <stdio.h>

int fact(int n) 
{    
  if (n == 0) {
    return(1);
  } else {
    return(n * fact(n-1)); 
  }
}

int main(int argc, char *argv[])
{
  int n, m;
  
  printf("Enter a number: ");
  scanf("%d", &n); 
  for (int i = 0; i < n; i++) {
    m = fact(i); 
    printf("Factorial of %d is %d.\n", i, m);    
  }
  
  printf("-2147483648 * 2 is %d\n", -2147483648 * 2);
  return 0;
}
