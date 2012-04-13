#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"


int main(int argc, char* argv[]) {
   int i, n;
   FILE* in;
   char fname[256];
   char string[256];
   symbol_t ts;
   entry_t* dado;

   if (argc!=3) {
      n = 20;
      strcpy(fname, "teste-symbol-table.txt");
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
   dado = lookup(ts, "Nicolas");
   if (dado == NULL)
	   printf("Test of a look-up in an empty table... OKAY.\n");
   else
	   printf("Test of a look-up in an empty table... ERROR.\n");
   for (i=0 ; i<n ; i++) {
      fscanf(in, "%s", &string); 
      printf("Trying to insert the string %s in the table...", string);
      dado = (entry_t*)malloc(sizeof(entry_t));
      dado->name = (char*)malloc(sizeof(char)*strlen(string));
      strcpy(dado->name, string);
      insert( &ts, dado );
      printf("... OKAY.\n");
   }
   fclose(in);
   /* Make a lookup to verify */
   in = fopen(fname, "r");
   for (i=0 ; i<n ; i++) {
      fscanf(in, "%s", &string); 
      printf("Trying to look-up the string %s in the table...\n", string);
      dado = lookup( ts, string );
      if (dado == NULL)
	   printf("Test of look-up(%s)... ERROR.\n", string);
      else {
	   printf("Test of look-up(%s)... OKAY. %s = %s.\n", string, string, dado->name);
      }
   }
   fclose(in);
   dado = lookup(ts, "NiCoLaS");
   if (dado == NULL)
	   printf("Test of a look-up of something weird... OKAY.\n");
   else
	   printf("Test of a look-up of something weird... ERROR.\n");
   
   print_table(ts);
   return(0);
}
