#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char temp = 0, *f;
    int count = 0;

    f = malloc(sizeof(char));

    while (scanf("%s", &temp) > 0){
        ++count;
        f[count] = temp;
    }
    


    return 0;
}