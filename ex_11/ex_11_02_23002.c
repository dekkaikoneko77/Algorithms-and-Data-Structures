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



void push_heap(T, x) {x
    size = size + 1;
    T[size] = x;
    k = size;
    while (T[k/2] < T[k] && 1 < k) {
        swap(T[k], T[k/2]);
        k = k / 2;
    }
}


int main(void) {

}