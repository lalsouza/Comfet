# Etapa2
# Todas as variaveis nao-declaradas aqui estao definidas em Comfet/Makefile

all: pico.c

pico.c: scanner.l tokens.h
	lex -o pico.c scanner.l

install: pico.c scanner.l tokens.h
	cp pico.c $(INC_DIR);\
cp tokens.h $(INC_DIR)

clean:
	rm -f pico.o; rm -f pico.c
