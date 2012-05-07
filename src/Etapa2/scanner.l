 /* Secao das declaracoes */

%option noyywrap
  /* Sera copiado no .c final */
%{
    #include <stdlib.h>
    #include <string.h>
   
    /* este include eh importante... */
    #include "tokens.h"
  
%}
 
  /* Definicoes regulares */
LETRA ([a-z]|[A-Z])
DIGITO ([0-9])

%%

 /* Secao das Regras de traducao */
 /* O que consta aqui eh puramente ilustrativo... 
  * Ver tambem "tokens.h" para a definicao de DIG e OPCMP
  */
INT {return (INT);}
DOUBLE {return (DOUBLE);}
FLOAT {return (FLOAT);}
CHAR {return (CHAR);}

"*" {return ('*');}
"+" {return ('+');}
"-" {return ('-');}
"/" {return ('/');}
"," {return (',');}
";" {return (';');}
"'" {return (QUOTE);}
"\"" {return (DQUOTE);}
"(" {return ('(');}
")" {return (')');}
"[" {return ('[');}
"]" {return (']');}
"{" {return ('{');}
"}" {return ('}');}
"<" {return ('<');}
">" {return ('>');}
"=" {return ('=');}
"<=" {return (LE);}
">=" {return (GE);}
"==" {return (EQ);}
"!" {return ('!');}
"!=" {return (NE);}
"&&" {return (AND);}
"||" {return (OR);}
IF {return (IF);}
THEN {return (THEN);}
ELSE {return (ELSE);}
WHILE {return (WHILE);}
{DIGITO}*[\.]{DIGITO}+([eE][+-]{DIGITO}+)? {return (F_LIT);}
{DIGITO}+ {return (INT_LIT);}
({LETRA})+({LETRA}|{DIGITO}|[_])* { return (IDF);}

[ \t\n]* { printf("BRANCO");}

. { printf("Erro lexical - caractere nao reconhecido: %c.\n", yytext[0]);
    exit(-1);}

%%

/* Secao dos  Procedimentos auxiliares  */

/* Para redefinir a entrada padrao do LEX. */

extern FILE *yyin;
