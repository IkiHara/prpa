#include <stdio.h>

void bubblesort(int * a, int A)
{
    for(int i = 0; i < A; ++i)
    {
        for(int j = 0; j < A; ++j)
        {
            if(a[i] > a[i+1])
            {
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
    }
}

void tisk(int * a, int A)
{
    for(int i = 0; i < A; ++i)
        printf("%i ", a[i]);
    printf("\n");
}

void tisk_void(void * a, int A, int size)
{
    for(int j = 0; j < A; ++j)
    {
        printf("%i ", *((char *)a + j*size));
    }
    printf("\n");
}

int main(void)
{
    int a[] = {6, 7, 3, 4, 2, 1, 7, 5};
    short b[] = {3, 5, 7, 1};
    bubblesort(a, 8);
    tisk(a, 8);
    tisk_void((void *)a, 8, sizeof(int));
    tisk_void((void *)b, 4, sizeof(short));
}