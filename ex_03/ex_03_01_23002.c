#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int max;
    int sp;
} Stack;

Stack* initStack(int max) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)calloc(max, sizeof(int));
    stack->max = max;
    stack->sp = 0;
    return stack;
}

void clear(Stack *stack) {
    stack->sp = 0;
}

void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

int push(Stack *stack, int value) {
    if (fullstack(stack) == 0) {        
        stack->data[stack->sp] = value;
        stack->sp++;
        return 0;
    } 
    return -1;
    
}

int pop(Stack *stack) {
    if (nostack(stack) == 0) {
        stack->sp--;
        return stack->data[stack->sp];
    }
    return -1;
}

int peek(Stack *stack) {
    if (nostack(stack) == 0) {
        return stack->data[stack->sp - 1];
    }
    return -1;
}

int display(Stack *stack, int sp) {
    return stack->data[sp];
}

int search(Stack *stack, int value) {
    int a = 0;
    for (int i = stack->sp - 1; i >= 0; i--) {
        if (stack->data[i] == value) {
            return stack->sp - 1 - i;
            a++;
        }
    }
    if (a == 0) {
        return -1;
    }
}

int nostack(Stack *stack) {
    if (stack->sp == 0) {
        return 1;
    }
    return 0;
}

int fullstack(Stack *stack) {
    if (stack->sp == stack->max) {
        return 1;
    }
    return 0;
}

int main(void) {
    Stack *stack = initStack(8);
    
    while(1) {
        int a = 0, b = 0;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            printf("push: %d\n", push(stack, b));
        } else if (a == 2) {
            printf("pop: %d\n", pop(stack));
        } else if (a == 3) {
            printf("peek:  %d\n", peek(stack));
        } else if (a == 4) {
            printf("display\n");
            if (stack->sp == 0) {
                printf("%d\n", -1);
                break;
            } else {
                for (int i = stack->sp - 1; i >= 0; i--) {
                    printf("%d ", display(stack, i));
                }
                printf("\n");
            }
        } else if (a == 5) {
            clear(stack);
        } else if (a == 6) {
            scanf("%d", &b);
            printf("search: %d\n", search(stack, b));
        } else if (a ==7) {

        }
    }
}