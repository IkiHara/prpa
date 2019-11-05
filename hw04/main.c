#include <stdio.h>

void strecha(int sirka, int vyska)
{
    int zleva = (sirka - 1)/2;

    for(int i = 0; i < zleva; i++)
    {
        for(int j = 0; j < zleva - i; j++)
        {
            printf(" ");
        }
        printf("X");
        if(i != 0)
        {
            for (int k = 0; k < (-1 + 2*i); k++)
            {
                printf(" ");
            }
            printf("X");
        }
        printf("\n");
    }
}

void dum(int sirka, int vyska)
{
    for(int i = 0; i < sirka; i++)
    {
        printf("X");
    }
    printf("\n");
    for(int i = 2; i < vyska; i++)
    {
        printf("X");
        for(int i = 1; i < (sirka - 1); i++)
        {
            printf(" ");
        }
        printf("X");
        printf("\n");
    }
    for(int i = 0; i < sirka; i++)
    {
        printf("X");
    }
    printf("\n");
}

int main()
{
    int sirka = 0;
    int vyska = 0;
    if(scanf("%i %i", &sirka, &vyska) != 0 && sirka != 0 && vyska != 0)
        if(sirka >= 3 && sirka <= 69)
        {
            if(vyska >= 3 && vyska <= 69)
            {
                if(sirka %2 != 0)
                {
                    strecha(sirka, vyska);
                    dum(sirka, vyska);
                }
                else
                {
                    fprintf(stderr,"Error: Sirka neni liche cislo!\n");
                    return 102;
                }
            }
            else
            {
                fprintf(stderr, "Error: Vstup mimo interval!\n");
                return 101;
            }
        }
        else
        {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }
    else
    {
        fprintf(stderr,"Error: Chybny vstup!\n");
        return 100;
    }
    return 0;
}
