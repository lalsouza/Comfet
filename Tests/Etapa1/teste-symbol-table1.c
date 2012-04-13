#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

/** Insercao/lookup de alguns strings simples. */


int main(int argc, char* argv[]) {
   int i, n;
   int test_ok = 1;
   FILE* in;
   char fname[256];
   char string[256];
   symbol_t ts;
   entry_t* dado;

   init_table(&ts);

   strcpy(string, "x");
   printf("Trying to insert the string %s in the table...", string);
   dado = (entry_t*)malloc(sizeof(entry_t));
   dado->name = (char*)malloc(sizeof(char)*strlen(string));
   strcpy(dado->name, string);
   insert( &ts, dado );
   test_ok = 1;
 
   strcpy(string, "tmp0");
   printf("Trying to insert the string %s in the table...", string);
   dado = (entry_t*)malloc(sizeof(entry_t));
   dado->name = (char*)malloc(sizeof(char)*strlen(string));
   strcpy(dado->name, string);
   insert( &ts, dado );
   test_ok = 1;
    
   strcpy(string, "this_is_a_variable_");
   printf("Trying to insert the string %s in the table...", string);
   dado = (entry_t*)malloc(sizeof(entry_t));
   dado->name = (char*)malloc(sizeof(char)*strlen(string));
   strcpy(dado->name, string);
   insert( &ts, dado );
   test_ok = 1;

   /* Make a lookup to verify */
   strcpy(string, "x");
   printf("Trying to look-up the string %s in the table...\n", string);
   dado = lookup( ts, string );
   if (dado == NULL) {
      printf("Test of look-up(%s)... ERROR.\n", string);
      test_ok = 0 && test_ok;
   }
   strcpy(string, "tmp0");
   printf("Trying to look-up the string %s in the table...\n", string);
   dado = lookup( ts, string );
   if (dado == NULL) {
      printf("Test of look-up(%s)... ERROR.\n", string);
      test_ok = 0 && test_ok;
   }
   strcpy(string, "this_is_a_variable_");
   printf("Trying to look-up the string %s in the table...\n", string);
   dado = lookup( ts, string );
   if (dado == NULL) {
      printf("Test of look-up(%s)... ERROR.\n", string);
      test_ok = 0 && test_ok;
   }
   dado = lookup(ts, "AlEsSiO");
   if (dado != NULL) {
      printf("Test of a look-up of something weird... ERROR.\n");
      test_ok = 0 && test_ok;
   } 
   if (test_ok)
     printf("Tudo OKAY.\n");
   /* print_table(ts); */
   return(0);
}
