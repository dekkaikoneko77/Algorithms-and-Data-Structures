#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int capacity;
    int size;
} BinaryTree;

BinaryTree* create_tree(int height) {
    BinaryTree* tree = malloc(sizeof(BinaryTree));
    tree->capacity = (1 << height);
    tree->data = calloc(tree->capacity, sizeof(int));
    tree->size = 1;
    return tree;
}

void append(BinaryTree* tree, int value) {
    if (tree == NULL) {
        return;
    }
    if (tree->size < tree->capacity) {
        tree->data[tree->size] = value;
        tree->size++;
    }
}

void delete_end(BinaryTree* tree) {
    if (tree == NULL) {
        return;
    }
    tree->size--;
}

void display(BinaryTree* tree) {
    int tmp = 1;

    printf("tree\n");
    if(tree == NULL) {
        printf("NULL\n");
        return;
    } else {
    for (int i = 1; i < tree->size; i++) {
        printf("%d ", tree->data[i]);
        if (i == tmp) {
            printf("\n");
            tmp = tmp * 2 + 1;
            }            
        }
    }
    printf("\n");
}

void search(BinaryTree* tree, int value) {
    if (tree == NULL) {
        return;
    }
    printf("index\n");
    for (int i = 1; i < tree->size; i++) {
        if (tree->data[i] == value) {
            printf("%d\n", i);
            return;
        }
    }
    printf("-1\n");
}

BinaryTree* free_tree(BinaryTree* tree) {
    if (tree == NULL) {
        return NULL;
    }
    free(tree->data);
    free(tree);
    return NULL;
}

int main() {
    BinaryTree* tree = create_tree(3);
    while(1) {
        int a = 0, b = 0;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            append(tree, b);
        } else if (a == 2) {
            delete_end(tree);
        } else if (a == 3) {
            display(tree);
        } else if (a == 4) {
            scanf("%d", &b);
            search(tree, b);
        } else if (a == 5) {
            tree = free_tree(tree);
        } else if (a == 6) {
            scanf("%d", &b);
            tree = create_tree(b);
        } else if (a < 0) {
            tree = free_tree(tree);
            break;
        }
    } 
    return 0;
}

