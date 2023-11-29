#ifndef _STACK_H
#define _STACK_H
#define SIZE 10
#include"bst.h"

typedef node_t *type_t;

typedef struct stack
{
    type_t arr[SIZE];
    int top;
}stack_t;

void init_stack(stack_t *st);
void push(stack_t *st,type_t data);


#endif

