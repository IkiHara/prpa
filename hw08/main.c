#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check (char ** inside, char * new, int size){
	for (int i = 0; i < size; ++i)
	{
		if (!strcmp(inside[i], new))
			return i;
	}
	return -1;
}
void fn(char * temp, int counter, char (*func)(char)){
    temp[counter] = func(temp[counter]);
}

char casesense(char input){
    if (input > 64 && input < 91)
		input ^= (1 << 5);	// zmena velikosti pismene
	return input;
}
 
char abconly(char input){
    if (input < 65 || input > 122 || (input > 90 && input < 97))
		return 0;	
	return input;
}

void sort1(char ** in, int * lenar, int * occ, int counter){
    for(int j = 0; j < counter; ++j){
        for (int i = 0; i < counter - 1; ++i){
		    if(occ[i+1] < occ[i]){
                char x[22];
    			strcpy(x, in[i+1]);
	    		strcpy(in[i+1], in[i]);
		    	strcpy(in[i], x);
                int y = occ[i+1];
                occ[i+1] = occ[i];
                occ[i] = y;
                int z = lenar[i+1];
                lenar[i+1] = lenar[i];
                lenar[i] = z;
            }
	    }
    }
}

void sort2 (char ** in, int * lenar, int * occ, int pos){
	for (int j = 0; j < pos; ++j){
		for (int i = 0; i < pos - 1; ++i){
			int k = (strcmp(in[i+1], in[i]) < 0); 
 			if (k){
				char x[22];
				strcpy(x, in[i+1]);
				strcpy(in[i+1], in[i]);
				strcpy(in[i], x);
                int y = occ[i+1];
                occ[i+1] = occ[i];
                occ[i] = y;
                int z = lenar[i+1];
                lenar[i+1] = lenar[i];
                lenar[i] = z;
			}
		}
	} 
}

int main(int argc, char *argv[]){
    int c = 0, s = 0, l = 0, se = 0, le = 0;
    
    for(int i = 1; i < argc; ++i){
        
        if(strcmp(argv[i], "-c") == 0)
            c = 1;

        else if(strcmp(argv[i], "-s") == 0){
            se = 1;
            
            if(strcmp(argv[i+1], "1") == 0)
                s = 1;
            
            else if(strcmp(argv[i+1], "2") == 0)
                s = 2;
        }

        else if(strcmp(argv[i], "-l") == 0){
            le = 1;
            l = atoi(argv[i+1]);
        }
    }

    if(se == 1 && (s == 0 || s > 2)){
        fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
        se = 0;
    }
    if(le == 1 && l > 20){
        fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
        le = 0;
    }

    int *occ, counter = 0, maxocc = 0, *lenar;
    char **ar, temp[22];

    ar = malloc(1*sizeof(char *));
    occ = malloc(1*sizeof(int));
    lenar = malloc(1*sizeof(int));
    
    if(c == 0){
        while(scanf("%s", temp) > 0){
            fn(temp, strlen(temp) - 1, abconly);
            fn(temp, 0, casesense);
            int checker = check(ar, temp, counter);
            if(checker < 0){
                ar[counter] = malloc(22);
                strcpy(ar[counter], temp);
                lenar[counter] = strlen(ar[counter]);
                occ[counter] = 1;
                ++counter;
                ar = realloc(ar, (1+counter)*sizeof(char *));
                occ = realloc(occ, (1+counter)*sizeof(int));
                lenar = realloc(lenar, (1+counter)*sizeof(int));
            }
            else
                ++occ[checker];
        }    
    }


    while(scanf("%s", temp) > 0){
        fn(temp, strlen(temp) - 1, abconly);
        int checker = check(ar, temp, counter);
        if(checker < 0){
            ar[counter] = malloc(22);
            strcpy(ar[counter], temp);
            lenar[counter] = strlen(ar[counter]);
            occ[counter] = 1;
            ++counter;
            ar = realloc(ar, (1+counter)*sizeof(char *));
            occ = realloc(occ, (1+counter)*sizeof(int));
            lenar = realloc(lenar, (1+counter)*sizeof(int));
        }
        else
            ++occ[checker];
    }

    if(s == 1)
        sort1(ar, lenar, occ, counter);
    
    if(s == 2)
        sort2(ar, lenar, occ, counter);
    
    if(l > 0 && le == 1){
        printf("Seznam slov:\n");
        for(int q = 0; q < counter; ++q)
            if(lenar[q] == l)
                printf("%-20s %i\n", ar[q], occ[q]);
    }

    else if(le == 0){
        printf("Seznam slov:\n");
        for(int q = 0; q < counter; ++q)
            printf("%-20s %i\n", ar[q], occ[q]);
    }
    printf("Pocet slov:%12i\n", counter);
    
    for(int i = 0; i < counter; ++i)
        for(int z = 0; z < counter; ++z){
            if(occ[z] > maxocc)
                maxocc = occ[z];
        }

    printf("Nejcastejsi:");
    for(int o = 0; o < counter; ++o)
        if(occ[o] == maxocc){
            static int a = 0;
            if(a == 0){
                printf("%12s", ar[o]);
                a = 1;
            }
            else if(a == 1)
                printf(" %s", ar[o]);            
        }
    printf("\n");
    
    printf("Nejmene caste:");
    for(int p = 0; p < counter; ++p)
        if(occ[p] == 1){
            static int b = 0;
            if(b == 0){
                printf("%12s", ar[p]);
                b = 1;
            }
            else if(b == 1)
                printf(" %s", ar[p]);            
        }
    printf("\n");

    for(int i = 0; i < counter; ++i)
        free(ar[i]);

    free(ar);
    free(occ);
    free(lenar);
    return 0;
}
