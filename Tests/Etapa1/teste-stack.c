#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char*argv[]) {
   stack s1;
   char* c;
   char text[50];
   int i ;

   init_stack( &s1 );
   if (empty( s1 ) ) {
     printf("Initialisation of the Stack... Okay.\n");
     printf("Empty Stack... Okay.\n");
   }
   else {
     printf("Initialisation of the Stack... Okay.\n");
     printf("Empty Stack... ERROR.\n");
   }
   for (i=0 ; i<50; i++) text[i] = (char)(i+'a'); 
   for (i=0 ; i<6 ; i++) {
      push(&s1, &(text[i]));
   }
   printf("Pushed 6 'char *'... Okay.\n");
   c = pop( &s1 ) ;
   if (*c == (char)(5+'a')) printf("Popped 1 item... OKAY.\n");
   else {
      printf("Popped 1 item... WRONG. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(5+'a'));
   }
   c = pop( &s1 ) ;
   if (*c == (char)(4+'a')) printf("Popped 1 item... OKAY.\n");
   else {
      printf("Popped 1 item... WRONG. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(4+'a'));
   }
   c = pop( &s1 ) ;
   if (*c == (char)(3+'a')) printf("Popped 1 item... OKAY.\n");
   else {
      printf("Popped 1 item... WRONG. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(3+'a'));
   }
   c = pop( &s1 ) ;
   if (*c == (char)(2+'a')) printf("Popped 1 item... OKAY.\n");
   else {
      printf("Popped 1 item... WRONG. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(2+'a'));
   }
   c = pop( &s1 ) ;
   if (*c == (char)(1+'a')) printf("Popped 1 item... OKAY.\n");
   else {
      printf("Popped 1 item... WRONG. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(1+'a'));
   }
   push(&s1, &(text[9]));
   printf("Pushd a new item.\n");
   c = pop( &s1 ) ;
   if (*c == (char)(9+'a')) printf("Popped 1 item... OKAY.\n");
   else {
      printf("Popped 1 item... WRONG. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(9+'a'));
   }
   c = pop( &s1 ) ;
   if (*c == (char)(0+'a')) printf("Popped 1 item... OKAY.\n");
   else {
      printf("Popped 1 item... WRONG. (");
      printf("Popped %c and should have been %c.)\n", *c, (char)(0+'a'));
   }
   if (empty(s1)) printf("Now the stack should be empy... OKAY!\n");
   else printf("Now the stack should be empy... ERROR!\n");
   return(0);
}
