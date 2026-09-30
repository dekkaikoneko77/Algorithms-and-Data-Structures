#include <stdio.h>
#include <math.h>

void search(int a[], int n, int key) {
    int left = 0, right = n - 1, mid = floor((left + right) / 2);
    printf("%d %d %d\n", left, right, mid);
    while (left <= right) {
        if (a[mid] < key) {
            left = floor((left + right) / 2) + 1;
            mid = floor((left + right) / 2);
        } else {
            right = floor((left + right) / 2) - 1;
            mid = floor((left + right) / 2);            
        }
        if (left < right) {
            printf("%d %d %d\n", left, right, mid);
        }
        if (a[mid] == key) {
            printf("%d\n", mid);            
            return;            
        }
        if (left >= right) {
            printf("-1\n");
            return;
        }
    }
}    

int main(void) {
    int n, key;
    int a[10000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
    }
    scanf("%d", &key);

    search(a, n, key);

    return 0;
}