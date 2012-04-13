#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
/** Tenta estorar com  1 000 000 elementos. */

#define SIZE 10000000
int main(int argc, char*argv[]) {
   stack s;
   double* elem;
   double* dado;
   int i ;

   dado = (double*)malloc(sizeof(double)*SIZE);
   if (!dado) {
      printf("Not enough memory to malloc. Nao eh culpa dos alunos.\n");
      exit(-1);
   }
   init_stack( &s );
   for (i=0 ; i<SIZE ; i++) {
      dado[i] = 10*(double)i;
      push(&s, &(dado[i]));
   }
   /* printf("Pushed SIZE 'double *'... OKAY.\n"); */
   for (i=0 ; i<SIZE/2 ; i++) {
      elem = pop(&s);
   }
   if ( (*elem - 10*(double)(SIZE/2))<1e-6 ) 
       printf("Popped SIZE/2 items... OKAY.\n");
   else 
      printf("Popped SIZE/2 items... ERROR.\n");
   return(0);
}
