#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p = (char *)malloc(5);

    for(int i = 0; i < 4; i++)
    {
        p[i] = 65 + i;
        printf("%c", *(p+i));
    }

    printf("\n");

    scanf("%s\n", p);
    printf("%s", p);

    printf("\n");
    free(p);
}
