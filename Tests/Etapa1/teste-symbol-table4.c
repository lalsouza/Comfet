#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

/** insercao de dois simbolos iguais */

int
main(int argc, char* argv[])
{
	int i, n;
	FILE* in;
	int test_ok = 1;
	char *string = "pneumoultramicroscopicossilicovulcanoconiotico\0"; /* palavra mais longa da lingua portuguesa, 46 letras */
	symbol_t ts;
	entry_t* dado;

	init_table(&ts);
	dado = (entry_t*)malloc(sizeof(entry_t));
	dado->name = (char*) malloc(sizeof(char)*strlen(string));
	strcpy(dado->name, string);
	insert( &ts, dado );
	if ( insert( &ts, dado ) != 0 ) /* nao deve conseguir inserir mesmo! */
		printf("OKAY\n");
	else
		printf("ERROR\n");
	return(0);
}
