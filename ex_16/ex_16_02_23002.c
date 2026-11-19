#include <stdio.h>

int max(int x[], int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m < x[i]) {
            m = x[i];
        }
    }
    return m;
}

void BB_01knapsack(int level, int n, int c, int W[], int V[], int r[], int y[], int *z, int ans[]) {
    int w = 0;
    for (int i = 0; i < n; i++) {
        if (y[i] == 1) {
            w += W[i];
        }
    }

    int v = 0;
    for (int i = 0; i < n; i++) {
        if (y[i] == 1) {
            v += V[i];
        }
    }

    if (level >= n) {
        if (w <= c && v > *z) {
            *z = v;
            for (int i = 0; i < n; i++) {
                ans[i] = y[i];
            }
        }
    } else {
        if (!(w > c)) {
            if (w == c) { 
                if (v > *z) {
                    *z = v;
                    for (int i = 0; i < n; i++) { 
                        ans[i] = y[i];
                    }
                }
            } else {
                int vb = v + (c - w) * max(&r[level], n - level);
                if (!(vb < *z)) { 
                    y[level] = 0;
                    BB_01knapsack(level + 1, n, c, W, V, r, y, z, ans);
                    y[level] = 1;
                    BB_01knapsack(level + 1, n, c, W, V, r, y, z, ans);
                    y[level] = 0;
                }
            }
        }
    }
}

int main(void) {
    int W[] = {4, 7, 6, 3};
    int V[] = {32, 35, 24, 9}; 
    int r[] = {8, 5, 4, 3}; 
    int n = 4;
    int c = 10;

    int y[4] = {0};
    int ans[4] = {0};
    int z = 0;

    BB_01knapsack(0, n, c, W, V, r, y, &z, ans);

    printf("%d\n", z);
    for (int i = 0; i < n; i++) {
        if (ans[i] == 1) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    printf("\n");
    return 0;
}