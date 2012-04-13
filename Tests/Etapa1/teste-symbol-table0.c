#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

/** Lookup em uma tabela vazia. */

int main(int argc, char* argv[]) {
   int i, n;
   FILE* in;
   char fname[256];
   char string[256];
   symbol_t ts;
   entry_t* dado;

   init_table(&ts);
   dado = lookup(ts, "Alessio");
   if (dado == NULL)
      printf("Test of a look-up in an empty table... OKAY.\n");
   else
      printf("Test of a look-up in an empty table... ERROR.\n");
   return(0);
}
