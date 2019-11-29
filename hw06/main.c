#include <stdio.h>

int main()
{
  int r = 0, s = 0, a = 0, b = 0, r2 = 0, s2 = 0, k = 0, i = 0;
  char o = 0;

  scanf("%d%d", &r, &s);
  int m1[r][s];

  for (a = 0; a < r; a++)
    for (b = 0; b < s; b++)
    {
      if(scanf("%d", &m1[a][b]) == 0)
      {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
        break;
      }
    }

  while(scanf("%c", &o) != 0)
  {
    if(o == '+' || o == '-' || o == '*')
      break;
  }

  scanf("%d%d", &r2, &s2);
  int m2[r2][s2];

  if(o == '*' && (r2 != s))
  {
    fprintf(stderr, "Error: Chybny vstup!\n");
    return 100;
  }

  else
  {
    for (a = 0; a < r2; a++)
      for (b = 0 ; b < s2; b++)
      {
        if(scanf("%d", &m2[a][b]) == 0)
        {
          fprintf(stderr, "Error: Chybny vstup!\n");
          return 100;
          break;
        }
      }

    if(scanf("%d", &i) > 10)
    {
      fprintf(stderr, "Error: Chybny vstup!\n");
      return 100;
    }
  }

  int plus[r][s];
  int minus[r][s];
  int krat[r][s2];
  if(o == '+')
  {
    printf("%d %d\n", r, s2);
    for (a = 0; a < r; a++) {
      for (b = 0 ; b < s; b++) {
        plus[a][b] = m1[a][b] + m2[a][b];
        if(b == 0)
          printf("%d", plus[a][b]);
        else
          printf(" %d", plus[a][b]);
      }
      printf("\n");
    }
  }

  else if (o == '-')
  {
    printf("%d %d\n", r, s2);
    for (a = 0; a < r; a++) {
      for (b = 0; b < s; b++) {
        minus[a][b] = m1[a][b] - m2[a][b];
        if(b == 0)
          printf("%d", minus[a][b]);
        else
          printf(" %d", minus[a][b]);
      }
      printf("\n");
    }
  }



  else if(o == '*')
  {
    for (a = 0; a < r; a++)
    {
      for (b = 0; b < s2; b++)
      {
        for (k = 0; k < r2; k++)
        {
          i = i + m1[a][k]*m2[k][b];
        }

        krat[a][b] = i;
        i = 0;
      }
    }

    printf("%d %d\n", r, s2);

    for (a = 0; a < r; a++) {
      for (b = 0; b < s2; b++)
        if(b == 0)
          printf("%d", krat[a][b]);
        else
          printf(" %d", krat[a][b]);

      printf("\n");
    }
  }

  else
  {
  fprintf(stderr, "Error: Chybny vstup!\n");
  return 100;
  }

  return 0;
}
