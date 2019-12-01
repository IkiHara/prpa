#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c = 0, s = 0, l = 0, se = 0, le = 0;
    
    if(argc > 6)
        return 100;
    
    for(int i = 1; i < argc; ++i)
    {
        if(strcmp(argv[i], "-c") == 0)
            c = 1;
        else if(strcmp(argv[i], "-s") == 0)
            se = 1;
        else if(strcmp(argv[i], "-l") == 0)
            le = 1;
        else if(strcmp(argv[i], "1") && strcmp(argv[i-1], "-s") == 0)
            s = atoi(argv[i]);
        else if(strcmp(argv[i], "2") && strcmp(argv[i-1], "-s") == 0)
            s = atoi(argv[i]);
        else if(strcmp(argv[i-1], "-l") == 0)
            l = atoi(argv[i]);
        else{
            printf("zadany parametr neni spravny\n");
            return 100;
        }
        printf("%s\n", argv[i]);
    }

    //printf("c = %i\n", c);
    //printf("se = %i\n", se);
    //printf("s = %i\n", s);
    //printf("le = %i\n", le);
    //printf("l = %i\n", l);

    if(se == 1 && (s == 0 || s > 2)){
        printf("zadany parametr -s neni spravny\n");
        return 100;
    }
    if(le == 1 && l == 0){
        printf("zadany parametr -l neni spravny\n");
        return 100;
    }

    return 0;
}