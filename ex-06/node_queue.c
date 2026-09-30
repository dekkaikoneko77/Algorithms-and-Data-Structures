#include "node_queue.h"

#include <stdio.h>
#include <stdlib.h>

// 初期化
Queue* init_queue(int max) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Node**)calloc(max, sizeof(Node*));
    queue->max = max;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    return queue;
}

// 空か確認
int is_empty(Queue* queue) {
    return queue->size == 0;
}

// 満杯か確認
int is_full(Queue* queue) {
    return queue->size == queue->max;
}

// enqueue
void enqueue(Queue* queue, Node* value) {
    if (is_full(queue)) {
        return;
    }
    queue->data[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->max;  // 循環
    queue->size++;
}

// dequeue
Node* dequeue(Queue* queue) {
    if (is_empty(queue)) {
        return NULL;
    }
    Node* node = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->max;  // 循環
    queue->size--;
    return node;
}

// 解放
void free_queue(Queue* queue) {
    free(queue->data);
    free(queue);
}

// クリア
void clear(Queue* queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}

