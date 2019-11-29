#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int size)
{
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size - 1; ++j)
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}

float get_median(int* a, int count)
{
    float median;
    if(count % 2 == 0)
        median = ((a[(count-1)/2]+(a[(count)/2]))/2);
    else median = a[count/2];
    return median;
}

void print1(float median, int counter, int high, int low)
{
    printf("Median %.2f\n", median);
    printf("Number count: %d\n", counter);
    printf("Min: %d\n", low);
    printf("Max: %d\n", high);
}

void printhist(int histcount, int high, int low, int maxsoa, int counter, int *occ, int *ar)
{
    int spread = high - low;
    double part = (double)spread / (double)histcount;
    
    for(int i = 0; i < histcount; ++i)
    {
        occ[i] = 0;
        for(int j = 0; j < counter; ++j)
            if(ar[j] >= (double)low + ((double)i*part) && ar[j] <= (double)low + ((double)(i+1)*part))
                ++occ[i];
    if(occ[i] > maxsoa)
        maxsoa = occ[i];
    }
    printf("Histogram:\n");
    for(int i = 0; i < histcount; ++i)
    {   
        printf("%5.1f - ", ((double)low + ((double)i*part)));
        printf("%5.1f|", ((double)low + ((double)(i+1)*part)));

        double eqcount = (((double)occ[i]/(double)maxsoa)*100)/4;
        for(int j = 0; j < (int)eqcount; ++j)
            printf("=");
        printf("\n");
    }
}

int main()
{
    int counter = 0, temp = 0, histcount = 0, maxsoa = -9999, high = maxsoa, low = 9999, *ar;
    
    if((scanf("%d", &histcount)) != 1)
    {
        fprintf(stderr, "Histogram size error\n");
        return 100;
    }

    int occ[histcount];
    
    ar = (int*)malloc(1*sizeof(int));

    while(scanf("%d", &temp) == 1)
    {
        ar[counter] = temp;
        ++counter;
        ar = (int*)realloc(ar, (5+counter)*sizeof(int));
        if(temp > high)
            high = temp;
        if(temp < low)
            low = temp;
    }
    
    sort(ar, counter);
    print1(get_median(ar, counter), counter, high, low);
    printhist(histcount, high, low, maxsoa, counter, occ, ar);
    
free(ar);
return 0;
}
