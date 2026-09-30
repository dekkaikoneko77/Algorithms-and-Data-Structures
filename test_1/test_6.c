#include <stdio.h>

int f1(int x, int k) {
    while (1){
        if (k == 1) {
            return x * x;
        } else {
            return f1(x, k - 1) * f1(x, k - 1);
        }

    }
}

int main(void) {
    int x, k;

    scanf("%d %d", &x, &k);
    printf("%d\n", f1(x, k));

    return 0;
}