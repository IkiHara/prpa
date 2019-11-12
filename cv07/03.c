#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int t = 0; t=a; a=b; b=t;}

void pole_print(int * a, int velikost)
{
    for(int i = 0; i < velikost; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}

void pole_sort(int * a, int velikost)
{
    int swapped;

    for(int j = 0; j < velikost; j++)
    {
        swapped = 0;
        for(int i = 0; i < velikost - 1; i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1])
                swapped = 1;
                /*int tmp = a[i];
                a[i] = a[i+1];
                a[i + 1] = tmp;
                */
            }
        }
        if (swapped == 0)
        {
            printf("%i/%i\n", j, velikost);
            return;
        }
    }
}

int main()
{
    int a, i = 0;
    int *p = (int *)malloc(sizeof(int));

    while(scanf("%i", &a) > 0)
    {
        //printf("%i ", a);
        p[i++] = a;
        p = realloc(p, (i+1)*sizeof(int)); //toto není chybně!
    }
    printf("i = %i\n", i);

    pole_print(p, i);
    pole_sort(p, i);
    pole_print(p, i);
    free(p);
    return 0;
}
