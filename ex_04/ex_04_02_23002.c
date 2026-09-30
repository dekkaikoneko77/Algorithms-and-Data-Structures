#include <stdio.h>

int add(int a[], int n) {
    if(n == 0){
        return a[0];
    }
    return a[n] + add(a, n - 1);
}

int main() {
    int a;
    scanf("%d", &a);
    int arr[a];
    for(int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }
    int result = add(arr, a - 1);
    printf("%d\n", result);
    return 0;
}