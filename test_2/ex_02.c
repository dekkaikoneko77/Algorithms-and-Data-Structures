#include <stdio.h>

int binary_search(int d[], int x, int left, int right) {
    int mid = (left + right) / 2;  // 中央のインデックスを求める
    if (left == right) {
        return -1;
    }
    if (d[mid] == x) {  // 探している値が見つかった場合はインデックスを返す
        return mid;
    } else if (d[mid] < x) {  // 探している値が中央より大きい場合は右側を再帰的に探索
        return binary_search(d, x, (left + right) / 2, right);
    } else {  // 探している値が中央より小さい場合は左側を再帰的に探索
        return binary_search(d, x, left, (left + right) / 2);
    }
}

int main() {
    int data[10000];
    int right,k;
    scanf("%d", &right);
    for(int i = 0; i < right; i++) {
        scanf("%d ", &data[i]);
    }
    scanf("%d", &k);
    printf("%d\n", binary_search(data, k, 0, right - 1 ));
}