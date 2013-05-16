%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
%}

/* A completar com seus tokens - compilar com 'yacc -d' */

%left '+' '-'
%left '*' '/'
%left OR
%left AND
%left NOT

%token INT
%token DOUBLE 
%token FLOAT
%token CHAR 


%token '*'
%token '+'
%token '-'
%token '/'
%token ','
%token ';'
%token QUOTE
%token DQUOTE
%token '('
%token ')'
%token '['
%token ']'
%token '{'
%token '}'
%token '<'
%token '>'
%token '='
%token LE
%token GE
%token EQ
%token '!'
%token NE
%token AND
%token OR


%token END
%token TRUE
%token FALSE
%token IF
%token THEN
%token ELSE
%token WHILE
%token F_LIT
%token INT_LIT
%token IDF
%token DO /*Adicionado*/

%%

blocoPrincipal: 	'{' blocoVarDeclaracao repete '}'
                	;

repete: 	blocoCorpo repete
		| 	blocoCorpo
		;

blocoVarDeclaracao: 		blocoId '=' blocoTipo ';' blocoVarDeclaracao  
		    			| 	blocoId '=' blocoTipo ';' 
	    				;

blocoTipo: 		INT
   			| 	FLOAT
   			| 	CHAR
			| 	DOUBLE
	   		; 

blocoId:		IDF ',' blocoId 
			| 	IDF  
	 		; 


blocoCorpo: 	expressaoArit blocoCorpo
		    | 	if blocoCorpo
		    | 	while blocoCorpo
		    | 	expressaoArit  
		    | 	if
		    | 	while
		    |	dowhile
		    ;

ident: 		IDF
   		| 	F_LIT
       	| 	INT_LIT
       	;

expressaoArit:  	ident '+' expressaoArit 
		 		| 	ident '-' expressaoArit 
	       	 	| 	ident '/' expressaoArit 
   			 	| 	ident '*' expressaoArit 
		       	| 	ident AND expressaoArit 
		       	| 	ident OR expressaoArit
			 	| 	ident condicao expressaoArit
			 	| 	ident ';'
         	 	;

condicao: 		'>' 
			| 	'<'
			| 	'='
			|	 GE
			| 	LE
			| 	EQ 
			| 	NE
			;

blocoCond : 	ident condicao ident
	    	| 	ident condicao expressaoArit
	    	;

comando: 	expressaoArit comando
		 | 	if comando
		 | 	while comando
		 | 	expressaoArit
		 | 	if
		 | 	while
		 |	dowhile
		 ;

if: 	IF '(' blocoCond ')' THEN '{' comando '}' 
	| 	IF '(' blocoCond ')' THEN '{' comando '}' ELSE '{' comando '}' 
    ;

while: 	WHILE '(' blocoCond ')' '{' comando '}'
		;

dowhile:  	DO '{' comando '}' WHILE '(' blocoCond ')' ';' /* Adicionado. */
			;


%%


 /* A partir daqui, insere-se qualquer código C necessário. */

/* #include "lex.yy.c" */  /* Para poder usar o scanner */
   #include "pico.c"

char* progname;
int lineno;

/*Comentário*/

int main(int argc, char* argv[]) 
{
   if (argc != 2) {
     printf("uso: %s <input_file>. Try again!\n", argv[0]);
     exit(-1);
   }
   yyin = fopen(argv[1], "r");
   if (!yyin) {
     printf("Uso: %s <input_file>. Could not find %s. Try again!\n", 
         argv[0], argv[1]);
     exit(-1);
   }

   progname = argv[0];
   

   if (!yyparse()) 
      printf("OKAY.\n");
   else 
      printf("ERROR.\n");



   
   return(0);
}

yyerror(char* s) {
  fprintf(stderr, "%s: %s", progname, s);
  fprintf(stderr, "line %d\n", lineno);
}