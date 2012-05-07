## Neste diretório, você pode colocar procedimentos para testes. 
## Exemplo de uso de Makefile
## OBJ_DIR e INC_DIR sao atualizados pelo Makefile principal, assim como
## CC e CFLAGS.

# A usar depois do 'make install' em src/Etapa1

all: teste1 teste2

teste1:
	$(CC) $(CFLAGS) -o teste1 $(OBJ_DIR)/* \
	   -I$(INC_DIR) test1.c

teste2:
	$(CC) $(CFLAGS) -o teste2 $(OBJ_DIR)/* \
	   -I$(INC_DIR) test2.c

clean:
	rm -f teste-lista1 teste-stack teste-symbol-table *.o
 