#include <stdio.h>

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
    tree->data[tree->size] = value;
    tree->size++;
}

void delete_end(BinaryTree* tree) {
    tree->size--;
}

void display(BinaryTree* tree) {
    int tmp = 0;
    printf("tree\n");
    for (int i = 1; i < tree->size; i++) {
        printf("%d ", tree->data[i]);
        if (i == 2 ^ tmp) {
            printf("\n");
            tmp++;
        }
    }
    printf("\n");
}

int search(BinaryTree* tree, int value) {
    for (int i = 1; i < tree->size; i++) {
        if (tree->data[i] == value) {
            return i;
        }
    }
    return -1;
}

void clear(BinaryTree* tree) {
    free(tree->data);
}


void free_tree(BinaryTree* tree) {
    free(tree->data);
    free(tree);
}

int main() {
    BinaryTree* tree = create_tree(3);
    while(1) {
        int a = 0, b = 0;
        scanf("%d", &a);
        if (a == 0) {
            scanf("%d", &b);
            append(tree, b);
        }
    } 

}

