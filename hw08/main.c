#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c = 0, s = 0, l = 0, se = 0, le = 0;
    
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
    }

    //printf("c = %i\n", c);
    //printf("se = %i\n", se);
    //printf("s = %i\n", s);
    //printf("le = %i\n", le);
    //printf("l = %i\n", l);

    if(se == 1 && (s == 0 || s > 2)){
        fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
        se = 0;
    }
    if(le == 1 && l > 20){
        fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
        le = 0;
    }

    int counter = 0;
    char *ar, temp;

    ar = (char*)malloc(1*sizeof(char));

    while(scanf("%s", &temp) == 1){
        ar[counter] = temp;
        ++counter;
        ar = (char*)realloc(ar, (1+counter)*sizeof(char));
    }

    for(int q = 0; q < counter; ++q)
        printf("%s\n", ar[q]);

    free(ar);
    return 0;
}
