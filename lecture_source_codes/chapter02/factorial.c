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
  m = fact(n); 
  printf("Factorial of %d is %d.\n", n, m);    
  return 0;
}
