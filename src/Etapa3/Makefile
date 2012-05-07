# Etapa 3
# Todas as variaveis nao-declaradas aqui estao definidas em Comfet/Makefile

all: comfet

comfet: comfet.c
	$(CC) $(CFLAGS) -o comfet $(OBJ_DIR)/stack.o \
-I$(INC_DIR) comfet.c

install: comfet.c comfet
	cp comfet $(BIN)

clean:
	rm -f comfet
