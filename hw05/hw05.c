#include <stdio.h>

char a[104], enc[100], comp[100];
int length;
int shoda, maxshoda = 0, offset, poczn;

void abc(int offset, char startchar, int length)
{
    for(int i = offset; i < offset + length; i++) {
        a[i] = (char)(startchar + i - offset);
    }
}

int shiftchar(char enc)
{
    int decrypted = 0;
    if(enc <= 90 && enc >= 65)
    {
        //decrypted = 0;
        decrypted = enc - 65;
    }
    else if(enc <= 122 && enc >= 97)
    {
        //decrypted = 0;
        decrypted = enc - 97 + 26;
    }
    return decrypted;
}

int main()
{
    abc(0, 65, 26);
    abc(26, 97, 26);
    abc(52, 65, 26);
    abc(78, 97, 26);

    scanf("%d\n", &length);
    char bs;
    char enc[length], comp[length];
    poczn = 0;

    for(int i = 0; i < length; i++)
    {
        char b = 0;
        scanf("%c", &b);
        if(b != 10 && ((b < 65) || (b > 122)))
        {
            fprintf(stderr, "Error: Chybny vstup!\n");
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
        fprintf(stderr, "Error: Chybna delka vstupu!\n");
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
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
            break;
        }
        if((b > 64 && b < 91) || (b > 96 && b < 123))
        {
            comp[i] = b;
            poczn++;
        }
    }

    for(int i = 0; i < 52; i++)
    {
        shoda = 0;
        for(int j = 0; j < length; j++)
        {
            if(comp[j] == (enc[j] + i))
                shoda++;
        }

        //printf("i : %d\n", i);
        //printf("shoda : %d\n", shoda);
        //printf("\n");

        if(shoda >= maxshoda)
        {
            maxshoda = shoda;
            offset = i;
        }
    }
    int decrypted = 0;
    for(int i = 0; i < length; i++)
    {
        if(enc[i] <= 'Z' && enc[i] >= 'A')
        {
            //decrypted = 0;
            decrypted = a[(enc[i] - 65) + offset];
        }
        else if(enc[i] <= 'z' && enc[i] >= 'a')
        {
            //decrypted = 0;
            decrypted = a[(enc[i] - 97 + 26) + offset];
        }
        //printf("%c", decrypted);
    }

    if(offset < 26)
    {
        for(int i = 0; i < length; i++)
        {

            if(enc[i] <= 'Z' && enc[i] >= 'A')
            {
                //decrypted = 0;
                decrypted = a[(enc[i] - 65) + offset];
            }
            else if(enc[i] <= 'z' && enc[i] >= 'a')
            {
                //decrypted = 0;
                decrypted = a[(enc[i] - 97 + 26) + offset];
            }
            printf("%c", decrypted);
        }
    }
    else
    {
        offset = offset - 26;
        for(int i = 0; i < length; i++)
        {
            if(enc[i] <= 'Z' && enc[i] >= 'A')
            {
                //decrypted = 0;
                decrypted = a[(enc[i] - 65 + 52) - offset];
            }
            else if(enc[i] <= 'z' && enc[i] >= 'a')
            {
                //decrypted = 0;
                decrypted = a[(enc[i] - 71) - offset];
            }
            printf("%c", decrypted);
        }
    }
    //printf("\n");
    //for(int i = 0; i < 104; i++)
    //{printf("%c", a[i]);}
    //printf("\n");
    //printf("enc : ");
    //for(int i = 0; i < length; i++)
    //    printf("%c", enc[i]);
    //printf("\n");
    //printf("comp : ");
    //for(int i = 0; i < length; i++)
    //    printf("%c", comp[i]);
    printf("\n");
    return 0;
}
