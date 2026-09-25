#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int count = 0;

void start_stack(Stack *stack, int n) {
    for (int i = n; i >= 1; i--) {
        push(stack, i);
    }
}

void move_disk(Stack *from, Stack *to) {
    int disk = pop(from);
    push(to, disk);
    count++;
}

void display(Stack *A, Stack *B, Stack *C) {
    int i;

    printf("---\n");

    for (i = 0; i < A->sp; i++) {
        printf("v%d ", A->data[i]);
    }
    printf("\n");

    for (i = 0; i < B->sp; i++) {
        printf("v%d ", B->data[i]);
    }
    printf("\n");

    for (i = 0; i < C->sp; i++) {
        printf("v%d ", C->data[i]);
    }
    printf("\n");
}

void move(Stack *stack[], int n, int from, int work, int to) {
    if (n == 1) {
        move_disk(stack[from - 1], stack[to - 1]);
        display(stack[0], stack[1], stack[2]);
        return;
    }

    move(stack, n - 1, from, to, work);

    move_disk(stack[from - 1], stack[to - 1]);
    display(stack[0], stack[1], stack[2]);

    move(stack, n - 1, work, from, to);
}

int main(void) {
    int n;

    scanf("%d", &n);

    Stack *stack[3];

    for (int i = 0; i < 3; i++) {
        stack[i] = init_stack(n);
    }

    /* 開始状態 */
    start_stack(stack[0], n);

    display(stack[0], stack[1], stack[2]);

    /* ハノイの塔実行 */
    move(stack, n, 1, 2, 3);

    /* 総移動回数 */
    printf("%d\n", count);

    for (int i = 0; i < 3; i++) {
        free_stack(stack[i]);
    }

    return 0;
}