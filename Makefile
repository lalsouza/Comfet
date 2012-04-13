export
# Localizacao do diretorio principal de ComFet
COMFET_DIR   = /home/alessio/Disciplinas/Compiladores/2012/Projeto/ComFet

# Localizacao dos arquivos headers:
INC_DIR    = $(COMFET_DIR)/include
# Localizacao dos arquivos fontes
SRC_DIR    = $(COMFET_DIR)/src
# Localizacao dos arquivos objetos:
OBJ_DIR    = $(COMFET_DIR)/objects
# Localizacao dos arquivos de documentação:
DOC_DIR    = $(COMFET_DIR)/doc
# Localizacao do executavel
BIN        = $(COMFET_DIR)/bin

# Compilador C:
CC         = gcc

# Opcoes de compilacao:
CFLAGS     = -Wall -g

# Alterar a linha abaixo para compilar outras etapas. 
#   Por exemplo, para compilar as tres primeiras etapas:
# all: etapa1 etapa2 etapa3
#   ou ainda, para compilar apenas a sexta etapa:
# all: etapa6
all: etapa2 etapa1 

############# ETAPA 1 ##########################
DIR1    = $(SRC_DIR)/Etapa1
etapa1: $(DIR1)/stack.h $(DIR1)/symbol_table.h
	cd $(DIR1) && $(MAKE) -w install

test1: etapa1
	cd $(COMFET_DIR)/Tests && $(MAKE) -w

DIR2    = $(SRC_DIR)/Etapa2

etapa2: $(DIR2)/tokens.h $(DIR2)/scanner.l
	cd $(DIR2) && $(MAKE) -w install

test2: etapa2
	cd $(COMFET_DIR)/Tests && $(MAKE) -w

clean:
	rm -f $(INC_DIR)/* $(OBJ_DIR)/* ; \
	cd $(DIR1) && $(MAKE) -w clean ; \
	cd $(COMFET_DIR)/Tests && $(MAKE) -w clean ; \
