#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void display(Stack* stack){
    printf("---");

}

void move(Stack* stack,int n, int from, int work, int to) {
    if (n == 1) {
        printf("円盤%dを %d から %d へ移動\n", n, from, to);
        display(stack);
        return;
    }
    move(stack, n - 1, from, to, work);
    printf("円盤%dを %d から %d へ移動\n", n, from, to);
    move(stack, n - 1, work, from, to);
}

int main() {
    int a = 0;
    scanf("%d", &a);

    Stack* stack = init_stack(a);

    move(stack, a, 1, 2, 3);


}

