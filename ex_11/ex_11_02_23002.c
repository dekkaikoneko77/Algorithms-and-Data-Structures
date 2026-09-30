#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) do { int temp = (a); (a) = (b); (b) = temp; } while (0)

typedef struct {
    int *data; // ノードの値を格納する配列
    int capacity; // ヒープの最大容量
    int size; // 現在のノード数
} Heap;

Heap *create_heap(int capacity) {
    Heap *h = malloc(sizeof(Heap));
    h->capacity = capacity + 1;
    h->data = calloc(h->capacity, sizeof(int));
    h->size = 0;
    return h;
}

void push_heap(Heap *h, int x) {
    h->size = h->size + 1;
    h->data[h->size] = x;
    int k = h->size;

    while (k > 1 && h->data[k / 2] < h->data[k]) {
        swap(h->data[k], h->data[k / 2]);
        k = k / 2;
    }
}

int delete_maximum(Heap *h) {
    if (h->size <= 0) {
        return 0;
    }

    int max_value = h->data[1];
    h->data[1] = h->data[h->size];
    h->size = h->size - 1;

    int k = 1;
    while (2 * k <= h->size) {
        int child = 2 * k;
        if (child + 1 <= h->size && h->data[child] < h->data[child + 1]) {
            child = child + 1;
        }

        if (h->data[k] < h->data[child]) {
            swap(h->data[k], h->data[child]);
            k = child;
        } else {
            break;
        }
    }

    return max_value;
}

void heap_sort(int *arr, int n) {
    Heap *h = create_heap(n);

    for (int i = 0; i < n; i++) {
        push_heap(h, arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = delete_maximum(h);
    }

    free(h->data);
    free(h);
}

int main(void) {
    int arr[6];
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}