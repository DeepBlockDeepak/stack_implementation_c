#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>


#define STACK_EMPTY INT_MIN


struct node_t{
    int value;
    struct node_t *next;
};



bool push(struct node_t **stack, int val){

    // create the new node and memory check it
    struct node_t* new_node = malloc(sizeof(struct node_t));
    assert(new_node);

    new_node->value = val;
    new_node->next = *stack;

    *stack = new_node;

    printf("%d is val, %d is stack->value\n", val, (*stack)->value);
    
    return true;
}

int pop(struct node_t** stack){

    if(!(*stack)){
        return STACK_EMPTY;
    }

    
    struct node_t *tmp = *stack; // temporary node for deletion
    int pop_val = (*stack)->value; // retain the popped value

    *stack = (*stack)->next; // change head location
    free(tmp);

    return pop_val;
}


void pop_all(struct node_t** stack){
    printf("\nPopping all nodes off...\n");
    int popped_val;
    while((popped_val = pop(stack)) != STACK_EMPTY){
        printf("%d just got popped.\n", popped_val);
    }
    //printf("Stack popped it all off.\n");
}

int main(){


    struct node_t *stack = NULL;

    push(&stack, 44);

    
    printf("%d is last in.\n", stack->value);
    push(&stack, 55);
    printf("%d is last in.\n", stack->value);
    push(&stack, 99);
    printf("%d is last in.\n", stack->value);

    
    int popped_val = pop(&stack);
    printf("%d just got popped.bloop\n", popped_val);
    pop_all(&stack);



    return 0;
}