#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int D[], int left, int right) {
    int mid = (left + right) / 2;
    int k;
    if ((D[left] <= D[mid] && D[mid] <= D[right]) || (D[right] <= D[mid] && D[mid] <= D[left])) {
        k = mid;
    } else if ((D[mid] <= D[left] && D[left] <= D[right]) || (D[right] <= D[left] && D[left] <= D[mid])) {
        k = left;
    } else {
        k = right;
    }
    // ピボットを右端に置く
    swap(&D[k], &D[right]);
    int pivot = D[right];
    int i = left;
    int j = right - 1;
    while (1) {
        while (i <= j && D[i] < pivot) {
            i = i + 1;
        }
        while (j >= i && D[j] > pivot) {
            j = j - 1;
        }
        if (i >= j) break;
        swap(&D[i], &D[j]);
        i++; j--;
    }
    // ピボットを適切な位置に置く
    swap(&D[i], &D[right]);
    return i;
}

void quicksort(int D[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(D, left, right);
        quicksort(D, left, pivot_index - 1);
        quicksort(D, pivot_index + 1, right);
    }
}

int main(void) {
    int D[10], i;
    scanf("%d", &i);
    
    for (int j = 0; j < i; j++) {
        scanf("%d", &D[j]);
    }
    quicksort(D, 0, i - 1);

    for (int j = 0; j < i; j++) {
        printf("%d ", D[j]);
    }

    printf("\n");

    return 0;
}