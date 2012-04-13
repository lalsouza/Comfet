#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
/** Teste básico de pop() */

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
   if (*c != (char)(5+'a')) {
      printf("Popped 1 item... ERROR. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(5+'a'));
   }
   c = pop( &s1 ) ;
   if (*c != (char)(4+'a')) {
      printf("Popped 1 item... ERROR. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(4+'a'));
   }
   c = pop( &s1 ) ;
   if (*c != (char)(3+'a')) {
      printf("Popped 1 item... ERROR. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(3+'a'));
   }
   c = pop( &s1 ) ;
   if (*c != (char)(2+'a')) {
      printf("Popped 1 item... ERROR. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(2+'a'));
   }
   c = pop( &s1 ) ;
   if (*c != (char)(1+'a')) {
      printf("Popped 1 item... ERROR. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(1+'a'));
   }
   else 
      printf("Testes do pop... OKAY.\n");
   return(0);
}
