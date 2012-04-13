#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
/** Testa apenas o init_stack + empty */

int main(int argc, char*argv[]) {
   stack s1;
   char* c;
   char text[50];
   int i ;

   init_stack( &s1 );
   if (empty( s1 ) ) {
     printf("Empty Stack... OKAY.\n");
   }
   else {
     printf("Empty Stack... ERROR.\n");
   }
   return(0);
}
