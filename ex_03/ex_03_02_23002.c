#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int max;
    int head;
    int tail;
    int size;
} Queue;

Queue* initQueue(int max) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)calloc(max, sizeof(int));
    queue->max = max;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
return queue;
}

int noqueue (Queue *queue) {
    if (queue->size == 0) {
        return 1;
    }
    return 0;
}

int fullqueue(Queue *queue) {
    if (queue->size == queue->max) {
        return 1;
    }
    return 0;
}

void clear(Queue *queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}

void freeQueue(Queue *queue) {
    free(queue->data);
    free(queue);
}

int enqueue(Queue *queue, int value) {
    if (fullqueue(queue) == 0) {
        queue->data[queue->tail] = value;
        queue->tail = (queue->tail + 1) % queue->max;
        queue->size++;
        return 0;
    } 
    return -1;    
}

int dequeue(Queue *queue) {
    if (noqueue(queue) == 0) {
        int value = queue->data[queue->head];
        queue->head = (queue->head + 1) % queue->max;
        queue->size--;
        return value;
    }
    return -1;
}

int peek(Queue *queue) {
    if (noqueue(queue) == 0) {
        return queue->data[queue->head];
    }
    return -1;
}

int display(Queue *queue, int index) {
    return queue->data[index];
}

int search(Queue *queue, int value) {
    for (int i = 0; i < queue->size; i++) {
        int actual_index = (queue->head + i) % queue->max;
        if (queue->data[actual_index] == value) {
            return queue->size - i;
        }
    }
    return -1;
}
 
int main(void) {
    Queue *queue = initQueue(8);
    
    while(1) {
        int a = 0, b = 0;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            printf("enqueue: %d\n", enqueue(queue, b));
        } else if (a == 2) {
            printf("dequeue: %d\n", dequeue(queue));
        } else if (a == 3) {
            printf("peek:  %d\n", peek(queue));
        } else if (a == 4) {
            printf("display\n");
            if (queue->size == 0) {
                printf("%d\n", -1);
            } else {
                for (int i = 0; i < queue->size; i++) {
                    int actual_index = (queue->head + i) % queue->max;
                    printf("%d\n", display(queue, actual_index));
                }
            }
        } else if (a == 5) {
            clear(queue);
        } else if (a == 6) {
            scanf("%d", &b);
            printf("search: %d\n", search(queue, b));
        } else if (a == 7) {
            printf("empty: %d\n", noqueue(queue));
        } else if (a == 8) {
            printf("full: %d\n", fullqueue(queue));
        } else if (a < 0) {
            freeQueue(queue);
            break;
        }
    }
}