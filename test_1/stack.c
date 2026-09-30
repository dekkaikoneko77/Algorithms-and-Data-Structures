#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

// 初期化
Stack *init_stack(int max) {
    // Stackのメモリを確保
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    // スタックのデータを格納する配列のメモリを確保
    stack->data = (int *)calloc(max, sizeof(int));
    // スタックの最大容量を設定
    stack->max = max;
    // スタックポインタを初期化
    stack->sp = 0;

    return stack;
}

// 空か確認
int is_empty(Stack *stack) {
    return stack->sp == 0;
}

// 満杯か確認
int is_full(Stack *s) {
    return s->sp == s->max;
}

// push
void push(Stack *stack, int value) {
    if (stack->max <= stack->sp) {
        return;
    }
    stack->data[stack->sp] = value;
    stack->sp++;
}

// pop
int pop(Stack *stack) {
    if (stack->sp <= 0) {
        return -1;
    }
    stack->sp--;
    return stack->data[stack->sp];
}

// スタックの先頭要素を確認
int peek(Stack *stack) {
    if (stack->sp <= 0) {
        return -1;
    }
    return stack->data[stack->sp - 1];
}

// 解放
void free_stack(Stack *stack) {
    free(stack->data);
    free(stack);
}

// スタックを空にする
void clear(Stack *stack) {
    stack->sp = 0;
}

// 探索
int search(Stack *stack, int value) {
    for (int i = stack->sp - 1; i >= 0; i--) {
        if (stack->data[i] == value) {
            return i;
        }
    }
    return -1;
}
