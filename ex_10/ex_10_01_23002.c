#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct {
    int size;
    Node **table;
} HashTable;

int hash(HashTable *h, int x) {
    return x % h->size;
}

HashTable *init_table(int size) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->table = (Node **)calloc(size, sizeof(Node *));
    h->size = size;
    return h;
}

void insert(HashTable *h, int x) {
    int k = hash(h, x);
    if (h->table[k] == NULL) {
        h->table[k] = create_node(0); // 値はなんでもOK
    }
    if (!search_value(h->table[k], x)) {
        append_node(h->table[k], x);
    }
}

void delete_HashTable(HashTable *h, int x) {
    int k = hash(h, x);
    if (h->table[k] != NULL) {
        delete_node(h->table[k], x);
    }
}

void search_HashTable(HashTable *h, int x) {
    int k = hash(h, x);
    if (h->table[k] != NULL && search_value(h->table[k], x)) {
        printf("%d\n", 1);
    } else {
        printf("%d\n", 0);
    }
}

void print_HashTable(HashTable *h) {
    printf("table\n");
    for (int i = 0; i < h->size; i++) {        
        if (h->table[i] != NULL) {
            Node *current = h->table[i]->next;
            while (current != NULL) {
                printf("%d ", current->data);
                current = current->next;
            }
        }
        if (h->table[i] == NULL) {
            printf("n");
        }
        printf("\n");
    }
    printf("---\n");
}

void free_HashTable(HashTable *h) {
    for (int i = 0; i < h->size; i++) {
        if (h->table[i] != NULL) {
            delete_list(h->table[i]);
        }
    }
    free(h->table);
    free(h);
}

int main() {
    int a, b;
    HashTable *h = NULL;
    while(1) {
        scanf("%d", &a);
        if(a == 1) {
            scanf("%d", &b);
            h = init_table(b);
        } else if(a == 2) {
            scanf("%d", &b);
            insert(h, b);
        } else if(a == 3) {
            scanf("%d", &b);
            delete_HashTable(h, b);
        } else if(a == 4) {
            scanf("%d", &b);
            search_HashTable(h, b);
        } else if(a == 5) {
            print_HashTable(h);
        } else if(a < 0) {
            break;
        }   
    }
    free_HashTable(h);
    return 0;
}