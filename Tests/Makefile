## Neste diretório, você pode colocar procedimentos para testes. 
## Exemplo de uso de Makefile
## OBJ_DIR e INC_DIR sao atualizados pelo Makefile principal, assim como
## CC e CFLAGS.

# A usar depois do 'make install' em src/Etapa1

all: teste-lista1 teste-stack teste-symbol-table

teste-lista1: $(OBJ_DIR)/lista.o $(INC_DIR)/lista.h teste-lista1.c
	$(CC) $(CFLAGS) -o teste-lista1 $(OBJ_DIR)/lista.o -I$(INC_DIR) \
	   teste-lista1.c 

teste-stack: $(OBJ_DIR)/stack.o $(INC_DIR)/stack.h teste-stack.c
	$(CC) $(CFLAGS) -o teste-stack $(OBJ_DIR)/stack.o -I$(INC_DIR) \
	   teste-stack.c 

teste-symbol-table: $(OBJ_DIR)/symbol_table.o $(INC_DIR)/stack.h teste-symbol-table.c
	$(CC) $(CFLAGS) -o teste-symbol-table $(OBJ_DIR)/symbol_table.o -I$(INC_DIR) \
	   teste-symbol-table.c

clean:
	rm -f teste-lista1 teste-stack teste-symbol-table *.o
