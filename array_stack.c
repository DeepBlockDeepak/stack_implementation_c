#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 10
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN


bool push(int *stack ,int *top_ind, int val){
    //Check if the stack is full
    if(*top_ind >= STACK_LENGTH -1){
        return false;
    }

    // on to the next available slot
    (*top_ind)++;
    stack[*top_ind] = val;
    return true;
}

int pop(int stack[] , int *top_ind){
    if(*top_ind == EMPTY){
        return STACK_EMPTY;
    }

    // not removing the popped val, just allowing it
    //    to be overwritten later on
    int pop_val = stack[*top_ind];
    (*top_ind)--;

    return pop_val;
}

void array_printer(int arr[]){
    return;
}

void pop_all(int arr[], int *top_ind){
    
    int popped_val;
    while((popped_val = pop(arr, top_ind)) != STACK_EMPTY){
        printf("%d just got popped.\n", popped_val);
    }
    printf("Stack popped it all off.\n");
}

int main(){

    int stack[STACK_LENGTH];
    int top = EMPTY;

    push(stack, &top, 44);
    printf("%d is last in.\n", *(stack + top));
    push(stack, &top, 55);
    printf("%d is last in.\n", *(stack + top));
    push(stack, &top, 99);
    printf("%d is last in.\n", *(stack + top));

    /*
    int popped_val = pop(stack, &top);
    printf("%d just got popped.\n", popped_val);*/
    pop_all(stack, &top);



    return 0;
}