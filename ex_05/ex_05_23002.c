#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int data;
struct Node* left;
struct Node* right;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}



Node* add(Node* tree, int value) {
    if (tree == NULL) {
        return create_node(value);
    } else if (value < tree->data) {
        tree->left = add(tree->left, value);
    } else if (tree->data < value) {
        tree->right = add(tree->right, value);
    }
    return tree;
}

Node* find_min(Node* tree) {
    while (tree != NULL && tree->left != NULL) {
        tree = tree->left;
    }
    printf("%d\n", tree->data);
}

void preorder(Node* tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

Node* delete_node(Node* tree, int key) {
    if (key < tree->data) {
        tree->left = delete_node(tree->left, key);
    } else if (key > tree->data) {
        tree->right = delete_node(tree->right, key);
    } else if (key == tree->data) {
        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            return NULL;
        } else if (tree->left == NULL) {
            Node* temp = tree->right;
            free(tree);
            return temp;    
        } else if (tree->right == NULL) {
            Node* temp = tree->left;
            free(tree);
            return temp;    
        }
    }
}

void display(Node* tree, int value) {
    if (tree == NULL) {
        return;
    } else if (value == 1) {
        printf("%d ", tree->data);
        display(tree->left, value);
        display(tree->right, value);
    } else if (value == 2) {
        display(tree->left, value);
        printf("%d ", tree->data);
        display(tree->right, value);
    } else if (value == 3) {
        display(tree->left, value);
        display(tree->right, value);
        printf("%d ", tree->data);
    }
}

void free_tree(Node* tree) {
    if (tree != NULL) {
        return;
    }
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
    
}

int main() {
    int a = 0, b = 0;
    Node* tree = NULL;
    scanf("%d", &a);
    if (a == 1) {
        scanf("%d", &b);
        tree = create_node(b);
    } else if (a == 2){
        scanf("%d", &b);
        tree = add(tree, b);
    } else if (a == 3) {
        delete_node(tree, b);
    } else if (a == 4) {
        scanf("%d", &b);
        display(tree, b);
    } else if (a == 5) {
        free_tree(tree);
    } else if (a < 0) {
        free_tree(tree);
        return 0;
    }
}


