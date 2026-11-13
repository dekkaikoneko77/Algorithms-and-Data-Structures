#include <stdio.h>

typedef struct {
    int value;   /* 価値の和 */
    int set[11]; /* set[k] = 1 なら荷物 k を入れている */
} Memo;

/* アルゴリズム8.5：0-1ナップサック問題を動的計画法で解き、価値の和の最大値を返す */
int knapsack(int n, int c, int V[], int W[])
{
    Memo T[11][11] = {}; /* 表は0で初期化 */
    Memo m1, m2;
    int i, j;

    /* 1行目：荷物1だけを使う場合 */
    for (j = W[1]; j <= c; j++) {
        T[1][j].value = V[1];
        T[1][j].set[1] = 1;
    }

    for (j = 0; j <= c; j++) {
        for (i = 2; i <= n; i++) {
            if (j >= W[i]) {
                m1 = T[i - 1][j - W[i]]; /* (v1, S1) */
                m2 = T[i - 1][j];        /* (v2, S2) */
                if (m1.value + V[i] > m2.value) {
                    T[i][j] = m1;
                    T[i][j].value = m1.value + V[i];
                    T[i][j].set[i] = 1;  /* S1 ∪ {i} */
                } else {
                    T[i][j] = m2;
                }
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[n][c].value;
}

int main(void)
{
    int n, c;
    int V[11], W[11]; /* 荷物は1番から使う */
    int i;

    scanf("%d %d", &n, &c);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &V[i], &W[i]);
    }

    printf("%d\n", knapsack(n, c, V, W));

    return 0;
}