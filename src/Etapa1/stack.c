#include "stack.h"

void init_stack(stack* s){
    *s = NULL;
}

void free_stack(stack* s){
    void* item = NULL;
    while(1){
        item = pop(s);
        if (item == NULL)
            break;
        free(item);
    }
    return;
}

int empty(stack s){
    if (s == NULL){
        return 1;
    }
    return 0;
}

int push(stack* s, void* item){
    
    if (s == NULL){
        return 1;
    }
    
    stack_node* node = (stack_node*) malloc (sizeof(struct stack_node));
    
    if (node == NULL){
        return 1;
    }
    
    node->item = item;
    node->previous = *s;
    *s = node;
    
    return 0;
}
 
void* pop(stack* s){
    if (*s == NULL){
        return NULL;
    }
    stack_node* node = *s;
    *s = node->previous;
    void* item = node->item;
    free(node);
    return item;
}

void* top(stack s){
    if (s == NULL){
        return NULL;
    }
    return s->item;
}
