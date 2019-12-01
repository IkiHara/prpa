#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a, b;
    

    if(argc == 2)
    {
        printf("pocet argumentu = 1\n");
        if(strcmp(argv[1], "-c") == 0)
            printf("argument 1 je %s\n", argv[1]);
        else
        {
            printf("zadany parametr neni spravny\n");
            return 100;
        }
        
    }
    else if(argc == 3)
    {
        printf("pocet argumentu je 2\n");
        printf("argument 1 je %s\n", argv[1]);
        if(strcmp(argv[1], "-c") == 0)
            printf("argument 1 je %s\n", argv[1]);
        else if(strcmp(argv[1], "-c") != 0)
            if(strcmp(argv[1], "-s") == 0)
                if(strcmp(argv[2], "1") == 0)
                    a = 1;
                else if(strcmp(argv[2], "2") == 0)
                    a = 2;
                else
                {
                    printf("Hodnota parametru -s je neplatna\n");
                    return 100;
                }
            else if(strcmp(argv[1], "-l") == 0)
            {
                b = atoi(argv[2]);
                printf("parametr 1 je %d\n", b);
            }
            
            else
            {
                printf("zadany parametr neni spravny\n");
                return 100;
            }
        else {
            printf("zadany parametr neni spravny\n");
            return 100;
        }
    }
        
    else if(argc == 4)
    {
        printf("pocet argumentu je 3");
        printf("argument 1 je %s\n", argv[1]);
        if(strcmp(argv[1], "-c") != 0)
            if(strcmp(argv[1], "-s") == 0)
                if(strcmp(argv[2], "1") == 0){
                    a = 1;
                    printf("parametr 1 je %d\n", a);
                }
                else if(strcmp(argv[2], "2") == 0){
                    a = 2;
                    printf("parametr 1 je %d\n", a);
                }
                else{
                    printf("Hodnota parametru -s je neplatna\n");
                    return 100;
                }
            else if(strcmp(argv[1], "-l") == 0){
                b = atoi(argv[2]);
                printf("parametr 1 je %d\n", b);
            }
        if(strcmp(argv[1], "-c") != 0)
            if(strcmp(argv[1], "-s") == 0)
                if(strcmp(argv[2], "1") == 0){
                    a = 1;
                    printf("parametr 1 je %d\n", a);
                }
                else if(strcmp(argv[2], "2") == 0){
                    a = 2;
                    printf("parametr 1 je %d\n", a);
                }
                else{
                    printf("Hodnota parametru -s je neplatna\n");
                    return 100;
                }
            else if(strcmp(argv[1], "-l") == 0){
                b = atoi(argv[2]);
                printf("parametr 1 je %d\n", b);
            }
        printf("argument 2 je %s\n", argv[2]);
        printf("argument 3 je %s\n", argv[3]);
    }

    else if(argc == 5){
        printf("pocet argumentu je 4");
        printf("argument 1 je %s\n", argv[1]);
        printf("argument 2 je %s\n", argv[2]);
        printf("argument 3 je %s\n", argv[3]);
    }

    else if(argc == 6){
        printf("pocet argumentu je 5");
        printf("argument 1 je %s\n", argv[1]);
        printf("argument 2 je %s\n", argv[2]);
        printf("argument 3 je %s\n", argv[3]);
    }

    else
        printf("pocet argumentu je neplatny");
    
    return 0;
}