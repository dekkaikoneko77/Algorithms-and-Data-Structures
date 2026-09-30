#include <stdio.h>
#include "stack.h"

int f2(const char str[]) {
    Stack* stack = init_stack(10);
    for (int i = 0; i <= 10; i++){
        if (str[i] == '(') {
            push(stack, 1);
        } else if (str[i] == ')') {
            pop(stack);
        }
    }
    if (is_empty(stack) == 0) {
        free_stack(stack);
        return 0;
    } else {
        free_stack(stack);
        return 1;
    }
}

int main(void) {
    char str[11];
    scanf("%10s", str);
    printf("%d\n", f2(str));

    return 0;
}