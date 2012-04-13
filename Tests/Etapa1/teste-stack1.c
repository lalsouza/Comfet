#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/** Testa push - teste básico ! */
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
   printf("Pushed 6 'char *'... OKAY.\n");
   return(0);
}
