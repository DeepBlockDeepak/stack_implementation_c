#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define STACK_LENGTH 10
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN


struct node_t{
    int value;
    struct node_t *next;
};



bool push(struct node_t* stack, int val){

    // create the new node and memory check it
    struct node_t* new_node = malloc(sizeof(struct node_t));
    assert(new_node);

    new_node->value = val;
    new_node->next = stack;

    stack = new_node;
    
    return true;
}

int pop(struct node_t* stack){

    if(!stack){
        return STACK_EMPTY;
    }

    
    struct node_t *tmp = stack; // temporary node for deletion
    int pop_val = stack->value; // retain the popped value

    stack = stack->next; // change head location
    free(tmp);

    return pop_val;
}

void array_printer(int arr[]){
    return;
}

void pop_all(struct node_t* stack){
    
    int popped_val;
    while((popped_val = pop(stack)) != STACK_EMPTY){
        printf("%d just got popped.\n", popped_val);
    }
    printf("Stack popped it all off.\n");
}

int main(){


    struct node_t *stack = NULL;
    printf("%p == first stack\n", &stack);
    push(stack, 44);
    printf("%p == stack outside\n", &stack);
    
    //printf("%d is last in.\n", stack->value);
    push(stack, 55);
    //printf("%d is last in.\n", stack->value);
    push(stack, 99);
    //printf("%d is last in.\n", stack->value);

    /*
    int popped_val = pop(stack, &top);
    printf("%d just got popped.\n", popped_val);*/
    pop_all(stack);



    return 0;
}