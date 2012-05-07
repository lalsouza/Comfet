export
# Localizacao do diretorio principal de ComFet
COMFET_DIR   = $(PWD)

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
# Localizacao dos testes
TEST       = $(COMFET_DIR)/Tests

# Compilador C:
CC         = gcc

# Opcoes de compilacao:
CFLAGS     = -w -g

# Diretorios das Etapas

DIR1    = $(SRC_DIR)/Etapa1
DIR2    = $(SRC_DIR)/Etapa2
DIR3    = $(SRC_DIR)/Etapa3
DIR4    = $(SRC_DIR)/Etapa4
DIR5    = $(SRC_DIR)/Etapa5
DIR6    = $(SRC_DIR)/Etapa6
DIR7    = $(SRC_DIR)/Etapa7

TDIR1    = $(TEST)/Etapa1
TDIR2    = $(TEST)/Etapa2
TDIR3    = $(TEST)/Etapa3
TDIR4    = $(TEST)/Etapa4
TDIR5    = $(TEST)/Etapa5
TDIR6    = $(TEST)/Etapa6
TDIR7    = $(TEST)/Etapa7

# Alterar a linha abaixo para compilar etapas desejadas
#   Por exemplo, para compilar  apenas as tres primeiras etapas:
# all: etapa1 etapa2 etapa3

all: etapa1 etapa2 etapa3

allteste: teste1

# ===== ETAPA 1 =====

etapa1: $(DIR1)/stack.h $(DIR1)/symbol_table.h $(DIR1)/stack.c $(DIR1)/symbol_table.c
	cd $(DIR1) && $(MAKE) -w install

teste1:
	cd $(TDIR1) && $(MAKE) -w install

# ===== ETAPA 2 =====

etapa2: $(DIR2)/tokens.h $(DIR2)/scanner.l
	cd $(DIR2) && $(MAKE) -w install

teste2: etapa2
	cd $(TDIR2) && $(MAKE) -w install
    
# ===== ETAPA 3 =====

etapa3: $(DIR3)/comfet.c
	cd $(DIR3) && $(MAKE) -w install

# ========= CLEAN =========#

clean:
	rm -f $(INC_DIR)/* $(OBJ_DIR)/* $(BIN)/*;\
echo Includes > $(INC_DIR)/README;\
echo Objects > $(OBJ_DIR)/README;\
echo Binaries > $(BIN)/README;\
cd $(DIR1) && $(MAKE) -w clean;\
cd $(DIR2) && $(MAKE) -w clean;\
cd $(DIR3) && $(MAKE) -w clean;\
cd $(TEST) && $(MAKE) -w clean
