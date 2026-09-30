#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data; // データ
    int state; // 要素の状態
} Bucket;

typedef struct {
    int size; // ハッシュ表の要素数
    Bucket *table; // データ配列
} HashTable;

HashTable *init_table(int size) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->table = (Bucket *)calloc(size, sizeof(Bucket));
    h->size = size;
    return h;
}

int hash(HashTable *h, int x) {
    return x % h->size;
}

int rehash(HashTable *h, int x) {
    return (x + 1) % h->size;
}

void insert(HashTable *h, int x) {
    int k = hash(h, x);
    for (int i = 0; i < h->size; i++) {
        if (h->table[k].state != 1) {
            h->table[k].data = x;
            h->table[k].state = 1;
            break;
        }
        k = rehash(h, k);
    }
}

void delete(HashTable *h, int x) {
    int k = hash(h, x);
    for (int i = 0; i < h->size; i++) {
        if (h->table[k].state == 1 && h->table[k].data == x) {
            h->table[k].state = -1;
            break;
        }
        k = rehash(h, k);
    }
}

void search(HashTable *h, int x) {
    int k = hash(h, x);
    for (int i = 0; i < h->size; i++) {
        if (h->table[k].state == 1 && h->table[k].data == x) {
            printf("%d\n", k);
            return;
        } 
        k = rehash(h, k);            
    }
    printf("-1\n");
}

void print_table(HashTable *h) {
    printf("table\n");
    for (int i = 0; i < h->size; i++) {
        if (h->table[i].state == 1) {
            printf("%d\n", h->table[i].data);
        } else {
            printf("n\n");
        }
    }
    printf("---\n");
}

void free_table(HashTable *h) {
    free(h->table);
    free(h);
}

int main(void) {
    int op, n;
    HashTable *h = NULL;
    while(1) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &n);
            h = init_table(n);
        } else if (op == 2) {
            scanf("%d", &n);
            insert(h, n);
        } else if (op == 3) {
            scanf("%d", &n);
            delete(h, n);
        } else if (op == 4) {
            scanf("%d", &n);
            search(h, n);
        } else if (op == 5) {
            print_table(h);
        } else if (op < 0) {
            free_table(h);
            break;
        }        
    }
    return 0;
}