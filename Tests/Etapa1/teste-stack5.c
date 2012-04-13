#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/** parametros invalidos (NULL)*/

int
main(int argc, char*argv[])
{
	stack s;
	unsigned char byte = 's';

	/*init_stack(NULL);*/		/* referencia nao existente. deveria ser testada, mas Nicolas prometeu que seria bem usado.*/

	init_stack(&s);

	if ( push(NULL, &byte) != 0 ) 	/* == 0 inseriu o que nao podia. */
		printf("OKAY\n");
	else
		printf("ERROR\n");

	if ( push(NULL, NULL) != 0 ) 	/* == 0 inseriu o que nao podia. */
		printf("OKAY\n");
	else
		printf("ERROR\n");

	if ( push(&s, NULL) == 0 ) 	/* deve poder inserir NULL */
		printf("OKAY\n");
	else
		printf("ERROR\n");

	if ( pop(NULL) == NULL ) 	/* retorna nada. */
		printf("OKAY\n");
	else
		printf("ERROR\n");

	/* top nao tinha sido testado ainda. */
	if ( top(s) == NULL ) /* retorna nada. */
		printf("OKAY\n");
	else
		printf("ERROR\n");

	return(0);
}
