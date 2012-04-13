#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/** Testa combinacoes mais complexas de push/pop */

int main(int argc, char*argv[]) {
   stack s1;
   char* c;
   char text[50];
   int i ;

   init_stack( &s1 );
   for (i=0 ; i<50; i++) text[i] = (char)(i+'a'); 
   for (i=0 ; i<6 ; i++) {
      push(&s1, &(text[i]));
   }
   c = pop( &s1 ) ;
   c = pop( &s1 ) ;
   c = pop( &s1 ) ;
   c = pop( &s1 ) ;
   c = pop( &s1 ) ;
   push(&s1, &(text[9]));
   printf("Pushd a new item.\n");
   c = pop( &s1 ) ;
   if (*c != (char)(9+'a')) {
      printf("Popped 1 item... ERROR. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(9+'a'));
   }
   c = pop( &s1 ) ;
   if (*c != (char)(0+'a')) {
      printf("Popped 1 item... ERROR. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(0+'a'));
   }
   if (empty(s1)) printf("Now the stack should be empy... OKAY!\n");
   else 
      printf("Now the stack should be empy... ERROR!\n");
   return(0);
}
