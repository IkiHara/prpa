#include <stdio.h>
int kurzor = 0;

void stack_push(int * a, int data)
{
    a[kurzor++] = data;
}

int stack_pop(int * a)
{
    return a[--kurzor];
}

int main()
{
    int a[10] = {0};

    stack_push(a, 10);
    stack_push(a, 30);
    stack_push(a, 20);
    
    printf("%i\n", stack_pop(a));
    printf("%i\n", stack_pop(a));
}