#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
  char name1[12], name2[12];
  char mixed[25], title[20];
  
  strcpy(name1, "Rosalinda");
  strcpy(name2, "Zeke");
  strcpy(title, "This is the title.");
  
  printf("     %s\n\n", title);
  printf("Name 1 is %s\n", name1);
  printf("Name 2 is %s\n", name2);
  
  /* returns 1 if name1 > name2 */
  if (strcmp(name1, name2) > 0) {
    strcpy(mixed, name1);
  } else {
    strcpy(mixed, name2);
  }
  printf("The biggest name alphabetically is %s\n", mixed);
  
  strcpy(mixed, name1);
  strcat(mixed, "  ");
  strcat(mixed, name2);
  printf("Both names are %s\n", mixed);
  return 0;
}
