#include <stdio.h>

void merge(int D[], int left, int mid, int right) {
    int i, M[10]; 
    int x = left;
    int y = mid + 1;
    for (i = 0; i <= right - left; i = i + 1) {
        if (x == mid + 1) { // ソート済みの範囲外
            M[i] = D[y];
            y = y + 1;
        } else if (y == right + 1) { // ソート済みの範囲外
            M[i] = D[x];
            x = x + 1;
        } else if (D[x] <= D[y]) { // ⽐較
            M[i] = D[x];
            x = x + 1;
        } else { // ⽐較
            M[i] = D[y];
            y = y + 1;
        }
    }
    for (i = 0; i <= right - left; i = i + 1) { // コピー
        D[left + i] = M[i];
    }
}

void mergesort(int D[], int left, int right) {
    int mid = (left + right) / 2;
    if (left < mid) {
        mergesort(D, left, mid);
    }
    if (mid + 1 < right) {
        mergesort(D, mid + 1, right);
    }
    merge(D, left, mid, right);
}

int main(void) {
    int D[10], i;
    scanf("%d", &i);
    
    for (int j = 0; j < i; j++) {
        scanf("%d", &D[j]);
    }
    mergesort(D, 0, i - 1);

    for (int j = 0; j < i; j++) {
        printf("%d ", D[j]);
    }

    printf("\n");

    return 0;
}