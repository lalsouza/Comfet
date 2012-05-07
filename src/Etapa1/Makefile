# Etapa 1
# Todas as variaveis nao-declaradas aqui estao definidas em Comfet/Makefile

all: stack.o symbol_table.o

OBJ1     = symbol_table.o stack.o
HEAD1    = symbol_table.h stack.h

symbol_table.o: symbol_table.c symbol_table.h
	$(CC) $(CFLAGS) -c symbol_table.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

install: $(OBJ1) $(HEAD1)
	cp $(OBJ1) $(OBJ_DIR);\
cp $(HEAD1) $(INC_DIR)

clean:
	rm -f $(OBJ1)
