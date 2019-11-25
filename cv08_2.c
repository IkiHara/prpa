#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace (char *a, char b, char c)
{
  int A = strlen(a);
  for(int i = 0; i < A; ++i)
    if(a[i] == b) a[i] = c;
}

void replace2 (char *a, char *b, char *c)
{
  int A = strlen(a);
  int B = strlen(b);

  for(int i = 0; i < (A - B); i++)
  {
    int j;
    for(j = 0; j < B; j++)
    {
      if(*(a+i+j) != *(b+j))
        break;

      if(j == B)
        memcpy (a+i, c, B);
    }
  }
}

void toggle(char *a)
{
  int A = strlen(a);
  for(int i = 0; i < A; ++i)
    if((a[i] >= 65 && a[i] <= 90) || (a[i] >= 96 && a[i] <= 122))
      a[i] ^= 1 << 5;
}

int main()
{
  char *a;
  a = malloc(100);
  scanf("%[^\n]", a);
  printf("%s\n", a);
  replace(a, 'o', 'x');
  printf("%s\n", a);
  toggle(a);
  printf("%s\n", a);
  replace2(a, "XJ", "oo");
  printf("%s\n", a);
  return 0;
}
