/*
#include <stdio.h>
#include "stack.h"

int main () {
    
    stack s;
    init_stack(&s);
    
    printf("%d ", empty(s));
    
    int *a, *b, *c, *d;
    
    a = (int*) malloc (sizeof(int));
    *a = 1;
    b = (int*) malloc (sizeof(int));
    *b = 2;
    c = (int*) malloc (sizeof(int));
    *c = 3;
    d = (int*) malloc (sizeof(int));
    *d = 4;
    
    push(&s, a);
    push(&s, b);
    push(&s, c);
    push(&s, d);
    
    int e, f, g, h;
    
    e = *((int*)pop(&s));
    f = *((int*)pop(&s));
    g = *((int*)pop(&s));
    h = *((int*)pop(&s));
    
    
    printf("%d %d %d %d ", e, f, g, h);
    
    push(&s, a);
    push(&s, b);
    push(&s, c);
    
    printf ("%d ", *((int*)top(s)));
    
    push(&s, d);
    
    
    
    printf("%d ", empty(s));
    
    free_stack(&s);
    
    printf("%d ", empty(s));
    
    return 0;
    
    
}

/* Saída esperada para implementação correta de stack.h
 * 1 4 3 2 1 3 0 1 
 * RUN SUCCESSFUL 
 */