#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tokens.h"
#include "pico.c"

typedef struct {
	int tipo; //terminal = 0 ; nao-terminal = 1
	int valor;
} Elemento;

typedef struct {
	int vet_tam;
	Elemento* vet;
} Transicao;

#define TERMINAL	0
#define NAOTERMINAL	1

#define TRANS_S 	0
#define TRANS_E 	1
#define TRANS_E2	2
#define TRANS_T		3
#define TRANS_T2	4
#define TRANS_F		5

#define TERM_MAIS		0
#define TERM_MENOS		1
#define TERM_VEZES		2
#define TERM_DIVIDIR	3
#define TERM_ABRE		4
#define TERM_FECHA		5
#define TERM_ID			6
#define TERM_INT		7
#define TERM_FLOAT		8
#define TERM_CIFRAO		9

Transicao* tabela[6][10];

void TraduzirToken(int*);

int main(void) {

    yyin = fopen("teste3-imput.txt", "r");

    int I;
    int K;
	for (I = 0; I < 6; I++)
		for (K = 0; K < 10; K++)
			tabela[I][K] = 0;

	Transicao* t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 2;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = NAOTERMINAL;
	t->vet[0].valor = TRANS_E;
	t->vet[1].tipo = TERMINAL;
	t->vet[1].valor = TERM_CIFRAO;
	tabela[TRANS_S][TERM_ABRE] = t;
	tabela[TRANS_S][TERM_ID] = t;
	tabela[TRANS_S][TERM_INT] = t;
	tabela[TRANS_S][TERM_FLOAT] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 2;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = NAOTERMINAL;
	t->vet[0].valor = TRANS_T;
	t->vet[1].tipo = NAOTERMINAL;
	t->vet[1].valor = TRANS_E2;
	tabela[TRANS_E][TERM_ABRE] = t;
	tabela[TRANS_E][TERM_ID] = t;
	tabela[TRANS_E][TERM_INT] = t;
	tabela[TRANS_E][TERM_FLOAT] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 3;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_MAIS;
	t->vet[1].tipo = NAOTERMINAL;
	t->vet[1].valor = TRANS_T;
	t->vet[2].tipo = NAOTERMINAL;
	t->vet[2].valor = TRANS_E2;
	tabela[TRANS_E2][TERM_MAIS] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 3;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_MENOS;
	t->vet[1].tipo = NAOTERMINAL;
	t->vet[1].valor = TRANS_T;
	t->vet[2].tipo = NAOTERMINAL;
	t->vet[2].valor = TRANS_E2;
	tabela[TRANS_E2][TERM_MENOS] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 0;
	t->vet = 0;
	tabela[TRANS_E2][TERM_FECHA] = t;
	tabela[TRANS_E2][TERM_CIFRAO] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 2;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = NAOTERMINAL;
	t->vet[0].valor = TRANS_F;
	t->vet[1].tipo = NAOTERMINAL;
	t->vet[1].valor = TRANS_T2;
	tabela[TRANS_T][TERM_ABRE] = t;
	tabela[TRANS_T][TERM_ID] = t;
	tabela[TRANS_T][TERM_INT] = t;
	tabela[TRANS_T][TERM_FLOAT] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 3;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_VEZES;
	t->vet[1].tipo = NAOTERMINAL;
	t->vet[1].valor = TRANS_F;
	t->vet[2].tipo = NAOTERMINAL;
	t->vet[2].valor = TRANS_T2;
	tabela[TRANS_T2][TERM_VEZES] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 3;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_DIVIDIR;
	t->vet[1].tipo = NAOTERMINAL;
	t->vet[1].valor = TRANS_F;
	t->vet[2].tipo = NAOTERMINAL;
	t->vet[2].valor = TRANS_T2;
	tabela[TRANS_T2][TERM_DIVIDIR] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 0;
	t->vet = 0;
	tabela[TRANS_T2][TERM_MAIS] = t;
	tabela[TRANS_T2][TERM_MENOS] = t;
	tabela[TRANS_T2][TERM_FECHA] = t;
	tabela[TRANS_T2][TERM_CIFRAO] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 3;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_ABRE;
	t->vet[1].tipo = NAOTERMINAL;
	t->vet[1].valor = TRANS_E;
	t->vet[2].tipo = TERMINAL;
	t->vet[2].valor = TERM_FECHA;
	tabela[TRANS_F][TERM_ABRE] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 1;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_ID;
	tabela[TRANS_F][TERM_ID] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 1;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_INT;
	tabela[TRANS_F][TERM_INT] = t;

	t = malloc(sizeof(Transicao));
	t->vet_tam = 1;
	t->vet = malloc(sizeof(Elemento) * t->vet_tam);
	t->vet[0].tipo = TERMINAL;
	t->vet[0].valor = TERM_FLOAT;
	tabela[TRANS_F][TERM_FLOAT] = t;

	//leitura de tokens
    
	stack stk;
	init_stack(&stk);
    
	Elemento* item;
	item = malloc(sizeof(Elemento));
	item->tipo = NAOTERMINAL;
	item->valor = TRANS_S;
    

	push(&stk, (void*) item);

	int deupau = 0;
	int token;
	Elemento* now;
    
    printf("========= Analise sintatica =========\n");
    
	do {
		token = yylex();
        printf("TOKEN = %d\n", token);
		TraduzirToken(&token);
        //printf("TOKEN Traduzido = %d\n", token);
        
		do {
			now = (Elemento*) top(stk);
            
            //printf("topo - Tipo %d valor %d\n",now->tipo, now->valor );
            
			if (now->tipo == TERMINAL) {
				if (now->valor != token) {
					deupau = 1;
				}
                pop(&stk);
				break;
			} else {
				Transicao* trans = tabela[now->valor][token];
				
                pop(&stk);

				if(trans==0){
					deupau=1;
					break;
				}
                //printf("Colocando na Pilha\n");
				for(I=trans->vet_tam-1;I>=0;I--){
					push(&stk,(void*)&trans->vet[I]);
                    /* 
                    Elemento* imprime;
                    imprime = (Elemento*) top(stk);
                    printf("Elemento %d - Tipo %d valor %d\n", I, imprime->tipo, imprime->valor );
                     */
				}
			}
		} while (1);
        
        if(!deupau)
            printf("OK\n");
        
		if(token==TERM_CIFRAO)
			break;
        
	}while(!deupau);

	if(deupau)
		printf("ERROR\n");
	else
		printf("OKAY\n");

	return EXIT_SUCCESS;
}

void TraduzirToken(int* t) {
	switch (*t) {
	case ('+'):
		*t = TERM_MAIS;
		break;
	case ('-'):
		*t = TERM_MENOS;
		break;
	case ('*'):
		*t = TERM_VEZES;
		break;
	case ('/'):
		*t = TERM_DIVIDIR;
		break;
	case ('('):
		*t = TERM_ABRE;
		break;
	case (')'):
		*t = TERM_FECHA;
		break;
	case (IDF):
		*t = TERM_ID;
		break;
	case (INT_LIT):
		*t = TERM_INT;
		break;
	case (F_LIT):
		*t = TERM_FLOAT;
		break;
    case (0):
        *t = TERM_CIFRAO;
        break;
	default:
		*t = -1;
	}
}
