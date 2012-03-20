#include "symbol_table.h"

#define EOS '\0'

int hashcrc(char* s){
    char *i;
    
    unsigned h = 0, highorder;
    
    for ( i = s; *i != EOS; i = i+1 ) {
        
        highorder = h & 0xf8000000;     // extract high-order 5 bits from h
                                        // 0xf8000000 is the hexadecimal representation
                                        // for the 32-bit number with the first five 
                                        // bits = 1 and the other bits = 0
        
        h = h << 5;                     // shift h left by 5 bits
        
        h = h ^ (highorder >> 27);      // move the highorder 5 bits to the low-order
                                        // end and XOR into h
        h = h ^ (*i);                   // XOR h and i
       
    }
    return h % PRIME;
}


int init_table(symbol_t* table)  {
    int i;
    for(i = 0; i < PRIME; i++) {
        table->entries[i] = NULL;
    }
    return 0;
}

void free_table(symbol_t* table){
    int i;
    for (i = 0; i < PRIME; i++) {
        if(table->entries[i] != NULL) {
            
            struct table_node_entry * current = table->entries[i];
            struct table_node_entry * next = current->next;
            
            free(current->entry_data);
            free(current);
            
            while(next != NULL) {
                current = next;
                next = current->next;
                free(current->entry_data);
                free(current);
            }

            table->entries[i] = NULL;
        }
    }
    return;
}


entry_t* lookup(symbol_t table, char* name){
    // A partir de um nome, calcula um hash
    // para associá-lo a um número inteiro
    int hash = hashcrc(name);
    // que será um índice para acessar a tabela de símbolos.
    // verifica se existe ponteiro
    if(table.entries[hash] != NULL) {

        struct table_node_entry * current = table.entries[hash]; // inicia com o primeiro nodo da lista encadeada

        // se não for a "entry" que estamos procurando (o "name" é diferente) e ainda existe um nodo seguinte...
        while(( strcmp(name, current->entry_data->name)) && (current->next != NULL)) {
            current = current->next; // vai para o nodo seguinte
        }

    // se existe, retorna o ponteiro
//        return table.entries[hash];
        if( ! strcmp(name, current->entry_data->name)) { // se o "name" é igual
            return current->entry_data;
        } else { // se o "name" não é igual, foi até o fim da lista encadeada e não encontrou, então retorna NULL
            return NULL;
        }
    } else {
    // senão, retorna null
        return NULL;
    }
}


int insert(symbol_t* table, entry_t* entry){
    if(lookup(*table, entry->name) != NULL) { // se a chave já existe, retorna um numero negativo.
        return -1;
    }

    // cria o nodo de lista encadeada para esta entrada
    struct table_node_entry * node = malloc(sizeof(struct table_node_entry));
    node->entry_data = entry;
    node->next = NULL;

    // calcula o hash para associá-lo a um inteiro
    int hash = hashcrc(entry->name);
    // e se não houver lista encadeada ainda
    // entao nenhum elemento foi adicionado ainda para esta chave
    // insere na tabela de símbolos
    if(table->entries[hash] == NULL) {
    // inicia a lista encadeada com este elemento
        table->entries[hash] = node;
    } else {
        // se a lista encadeada já existe, adiciona o elemento no inicio:
        node->next = table->entries[hash]; // o próximo do novo elemento é o primeiro elemento da lista
        table->entries[hash] = node; // agora, o primeiro elemento da lista passa a ser o elemento recem criado
    }

     return 0;
}

char* str_entry(char* retbuffer, entry_t* entry) {
    sprintf(retbuffer, "ENTRY: %s;\n\tType: %d;\n\tSize: %d;\n\tDesloc: %d.\n\n",
                       entry->name, entry->type, entry->size, entry->desloc);
    return retbuffer;
}


int print_table(symbol_t table){
    return print_file_table(stdout, table);
}

int print_file_table(FILE* out, symbol_t table){
    int entry_count = 0;
    // varre a tabela de símbolos
    int i = 0;
    for(i = 0; i < PRIME; i++) {
    // onde houver ponteiro, imprime o conteúdo da entrada
        if(table.entries[i] != NULL) {
            char tmp_string[500];

            struct table_node_entry *current = table.entries[i]; // inicia com o primeiro nodo da lista encadeada

            do {
                str_entry(tmp_string, current->entry_data);
                fprintf(out, "%s", tmp_string); // imprime o nodo
                entry_count++;
                current = current->next; // vai para o nodo seguinte
            } while(current != NULL);

        }
    }


    return entry_count;
}
