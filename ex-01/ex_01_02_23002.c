#include <stdio.h>

int sum(int arr[], int start, int end) {
    int s = 0;
    for(int i = start; i < end; i++) {
        s += arr[i];
    }
    return s;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int data[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int left = 0;
    int right = n;

    // 初回（全体）
    int total = sum(data, 0, n);
    printf("%d\n", total);

    while(right - left > 1) {
        int mid = (left + right) / 2;

        int left_sum = sum(data, left, mid);
        printf("%d\n", left_sum);

        int expected = 100 * (mid - left);

        if(left_sum != expected) {
            // 左に不良品
            right = mid;
        } else {
            // 右に不良品
            left = mid;
        }
    }

    // 答え（1-indexed）
    printf("%d\n", left + 1);

    return 0;
}