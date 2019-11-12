#include <stdio.h>
char a[104];
int length, shoda, maxshoda = 0, offset;
void abc()
{
    for(int i = 0; i < 26; i++) {
        a[i] = 65 + i;
        a[i + 26] = 97 + i;
        a[i + 52] = 65 + i;
        a[i + 78] = 97 + i;
    }
}
int shiftchar(char enc, int rotor)
{
    char id = 0;
    if(enc < 91)
        id = enc - 65;
    else
        id = enc - 71;
    return a[id + rotor];
}
int main()
{
    abc();
    scanf("%d\n", &length);
    char bs;
    char enc[length], comp[length];
    int poczn = 0;
        for(int i = 0; i < length; i++)
        {
            char b = 0;
            scanf("%c", &b);
            if(b != 10 && ((b < 65) || (b > 122)))
            {
                fprintf(stderr, "Error: Chybny vstup!");
                return 100;
                break;
            }
            else if(b == 10)
            {}
            else
            {
                enc[i] = b;
                poczn++;
            }
        }
        if(poczn != length)
        {
            fprintf(stderr, "Error: Chybna delka vstupu!");
            return 101;
        }
        poczn = 0;
        while(scanf("%c", &bs) != 10)
            break;

        for(int i = 0; i < length; i++)
        {
            char b = 0;
            scanf("%c", &b);
            if(b != 10 && ((b < 65) || (b > 122)))
            {
                fprintf(stderr, "Error: Chybny vstup!");
                return 100;
                break;
            }
            if((b > 64 && b < 91) || (b > 96 && b < 123))
            {
                comp[i] = b;
                poczn++;
            }
        }
    for(int o = 0; o < 52; o++)
    {
        shoda = 0;
        for(int i = 0; i < length; i++)
        {
            if(shiftchar(enc[i], o) == comp[i])
                shoda++;
        }
        if(shoda >= maxshoda)
        {
            maxshoda = shoda;
            offset = o;
        }
    }
    for(int i = 0; i < length; i++)
    {
        printf("%c", shiftchar(enc[i], offset));
    }
    printf("\n");
    return 0;
}
