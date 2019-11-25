#include <stdio.h>
#include <string.h>

int cmp (const char * a, const char * b)
{
  printf("delka a: %lu\n", strlen(a));
  printf("delka b: %lu\n", strlen(b));

  do
  {
    if(*(a++) != *(b++))
      return 1;
  } while (*a != '\0' && *b != '\0');

  return 0;
}

int main()
{
  char a[] = "ahoj";
  char c[] = "ahoj";
  char *b = "ahoj";
  char *d = "ahoj";

  printf("%p\t%p\t%p\t%p\n", a, c, b, d);

  d = "svete";
  //c = "svete";
  strcpy (c, "svete");
  c[4] = '\0';
  printf("%s\n", c);

  //b[3] = '\0';
  printf("%p\t%p\t%p\t%p\n", a, c, b, d);

  char *e;
  e = "nazdar!";
  printf("%p\n", e);

  printf("%i\n", cmp(a, "ahoj"));
  printf("%i\n", cmp(a, e));
  printf("%i\n", cmp(a, b));
}
