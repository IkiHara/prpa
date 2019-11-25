#include <stdio.h>

typedef struct jmeno
{
    int data;
    struct jmeno * next;  
} item;

int main()
{
    item a; a.data = 10;
    item b; b.data = 20;
    item c; c.data = 30;
    item d; d.data = 0;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    printf("a.data = %i\n", a.data);
    printf("b.data = %i\n", (a.next)->data);

    item * t = &a;
    do{
        printf("%i\n", t->data);
        t = t->next;
    } while(t->next != NULL);
}