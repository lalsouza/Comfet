# Tests Etapa2
# Todas as variaveis nao-declaradas aqui estao definidas em Comfet/Makefile


all: install

install: teste1 teste2 teste3 teste4 teste6

teste1: test1.c
	$(CC) $(CFLAGS) -o teste1 $(OBJ_DIR)/symbol_table.o \
-I$(INC_DIR) test1.c 

teste2: test2.c
	$(CC) $(CFLAGS) -o teste2 $(OBJ_DIR)/symbol_table.o \
-I$(INC_DIR) test2.c

teste3: test3.c
	$(CC) $(CFLAGS) -o teste3 $(OBJ_DIR)/symbol_table.o \
-I$(INC_DIR) test3.c

teste4: test4.c
	$(CC) $(CFLAGS) -o teste4 $(OBJ_DIR)/symbol_table.o \
-I$(INC_DIR) test4.c

teste6: test6.c
	$(CC) $(CFLAGS) -o teste6 $(OBJ_DIR)/symbol_table.o \
-I$(INC_DIR) test6.c
    
clean:
	rm -f teste1 teste2 teste3 teste4 teste6