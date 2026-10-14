#include <stdio.h>

typedef struct {
    int value; // 価値の和
    int set[10]; // 荷物番号の集合
} Memo;

int main(void) {

    int W[10] = {}, V[10] = {};
    int i, j, n, C;

    scanf("%d", &n);
    scanf("%d", &C);

    for (i = 0; i <= n; i++) {
        scanf("%d", &W[i]);
        scanf("%d", &V[i]);
    }

    Memo T[10][10] = {};

    for (i = 1; i <= n; i = i + 1) {
        for (j = 1; j <= C; j = j + 1) {
            if (j >= W[i]) {

                int v1 = T[i - 1][j - W[i]].value;
                int S1 = T[i - 1][j - W[i]].set;
                int v2 = T[i - 1][j].value;
                int S2 = T[i - 1][j].set;

                if (v1 + V[i] > v2) {
                    T[i][j].value = v1 + V[i];
                    T[i][j].set = S1;
                } else {
                    T[i][j].value = v2;
                    T[i][j].set = S2;
                }
            }
        }
    }
}