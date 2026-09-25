#include <stdio.h>

typedef struct {
    int *data; // ノードの値を格納する配列
    int capacity; // ⽊の最⼤容量
    int size; // 現在のノード数
} Heap;

Heap *create_heap(int capacity) {
    Heap *h = malloc(sizeof(Heap));
    h->capacity = capacity;
    h->data = calloc(h->capacity, sizeof(int));
    h->size = 0;
    return h;
}

void push_heap(Heap *h, int x) {
    h->size = h->size + 1;
    h->data[h->size] = x;
    int k = h->size;
    while (h->data[k/2] < h->data[k] && 1 < k) {
        swap(h->data[k], h->data[k/2]);
        k = k / 2;
    }
}

void delete_maximum(Heap *h) {
    h->data[1] = h->data[h->size];
    h->size = h->size - 1;
    int k = 1, big;
    while (2*k <= h->size) {
        if (2*k == h->size) {
            if (h->data[k] < h->data[2*k]) {
                swap(h->data[k], h->data[2*k]);
                k = 2 * k;
            } else {
                delete();
            }
        } else {
            if (h->data[2*k+1] < h->data[2*k]) {
                big = 2 * k;
            } else {
                big = 2 * k + 1;
            }
            if (h->data[k] < h->data[big]) {
                swap(h->data[k], h->data[big]);
                k = big;
            } else {
                delete();
            }
        }
    }
}

int main(void) {
    Heap *h = create_heap(6);
    for (int i = 1; i <= 5; i++) {
        push_heap(h, i);
    }

    for (int i = 1; i <= 5; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
    return 0;
}