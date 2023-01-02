
#include <stdio.h>  // needed for the definition of NULL, printf
#include <stdlib.h> // needed for malloc, free
#include <assert.h> // needed for the definition of assert()
#include <string.h> // for strlen

int is_space(char c)
{
  if (
      (c == ' ') || (c == '\t') || (c == '\n') || (c == '\r') || (c == '\f') || (c == '\r') || (c == '\v'))
  {
    return 1;
  }

  return 0;
}

// Why double pointer? Use ** when you want
// to preserve (OR retain change in) the Memory-Allocation or Assignme
// https://stackoverflow.com/questions/5580761/why-use-double-indirection-or-why-use-pointers-to-pointers
int first_white_space_sep_word(char *word, char **retword)
{
  // check degenerate case
  if (word == NULL || word[0] == '\0')
    return -1;

  int word_len = strlen(word);

  int ret_len = word_len; // by default return the whole word
  for (int i = 0; i < word_len; i++)
  {
    if (is_space(word[i]) == 1)
    {
      ret_len = i;
      break;
    }
  }

  *retword = (char *)malloc(sizeof(char) * (ret_len + 1));
  if (*retword == NULL)
    return -2;
  for (int i = 0; i < ret_len; i++)
  {
    (*retword)[i] = word[i];
  }
  (*retword)[ret_len] = '\0';
  return ret_len;
}

int main(int argc, char **argv)
{
  char *word = "what's up buddy";
  char *retword = NULL;
  int ret_len = first_white_space_sep_word(word, &retword);
  printf("%u\n", ret_len);
  printf("%s", retword);
}