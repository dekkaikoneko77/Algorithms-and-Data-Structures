#include <stdio.h>

int main(void) {
    int D[6];
    int i, j, x;
    int n = 6;

    for (i = 0; i < n; i++) {
        scanf("%d", &D[i]);
    }

    for (i = 1; i < n; i = i + 1) {
        x = D[i]; // 挿⼊したい値
        for (j = i; x < D[j -1] && 0 < j; j--) {
            D[j] = D[j - 1]; // D[j - 1]の⽅が⼤きいなら右にずらす
        }
        D[j] = x;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", D[i]);
    }

    printf("\n");
    return 0;

}