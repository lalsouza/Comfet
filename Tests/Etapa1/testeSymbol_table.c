#include <stdio.h>
#include "symbol_table.h"

int main () {
    symbol_t test_table;
    init_table(&test_table);
    int i;
    for(i = 0; i < 10; i++){
        char *buffer = (char*) malloc (500);
        scanf("%s", buffer);
        entry_t *entry = (entry_t*)malloc(sizeof(entry_t));
        entry->name = buffer;
        entry->size = i;
        entry->desloc = 10-i;
        entry->type = 100 + i*i;
        insert(&test_table,entry);
    }
    print_table(test_table);
    return 0;
}

/* Saída esperada para implementação correta de stack.h
 * 1 4 3 2 1 3 0 1 
 * RUN SUCCESSFUL 
 */