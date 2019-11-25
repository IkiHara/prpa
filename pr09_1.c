#include <stdio.h>

void tisk(int vyska, int sirka, int c[vyska][sirka])
{
    for(int i = 0; i < vyska; ++i)
        for(int j = 0; j < sirka; ++j)
            printf("%i ", c[vyska][sirka]);
    printf("\n");
}

int main(void)
{
    int pole[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    tisk(3, 3, pole);
    return 0;
}