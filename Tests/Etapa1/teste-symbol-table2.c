#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

/** Insercao/lookup de 20 strings. */

int main(int argc, char* argv[]) {
   int i, n;
   FILE* in;
   int test_ok = 1;
   char fname[256];
   char string[256];
   symbol_t ts;
   entry_t* dado;

   if (argc!=3) {
      n = 20;
      strcpy(fname, "teste-symbol-table2.txt");
      in = fopen(fname, "r");
   }
   else{ 
      n = atoi(argv[1]);
      strcpy(fname, argv[2]);
      in = fopen(fname, "r");
   }
   if (!in) {
      printf("Error: could not find file %s!\n", fname);
      exit(-1);
   }
   init_table(&ts);
   for (i=0 ; i<n ; i++) {
      fscanf(in, "%s", &string); 
      printf("Trying to insert the string %s in the table...", string);
      dado = (entry_t*)malloc(sizeof(entry_t));
      dado->name = (char*)malloc(sizeof(char)*strlen(string));
      strcpy(dado->name, string);
      insert( &ts, dado );
   }
   fclose(in);
   /* Make a lookup to verify */
   in = fopen(fname, "r");
   for (i=0 ; i<n ; i++) {
      fscanf(in, "%s", &string); 
      printf("Trying to look-up the string %s in the table...\n", string);
      dado = lookup( ts, string );
      if (dado == NULL) {
	   printf("Test of look-up(%s)... ERROR.\n", string);
	   test_ok = 0 && test_ok;
      }
      else {
	   test_ok = 1 && test_ok;
      }
   }
   fclose(in);
   if (test_ok)
     printf("Teste OKAY.\n");
   /* print_table(ts); */
   return(0);
}
