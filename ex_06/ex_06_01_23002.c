#include "node_queue.h"

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

int count_nodes(Node* tree)
{
    if (tree == NULL) {
        return 0;
    }

    return 1
         + count_nodes(tree->left)
         + count_nodes(tree->right);
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
    return tree;
}

Node* find_max(Node* tree) {
    while (tree != NULL && tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

Node* free_tree(Node* tree) {
    if (tree == NULL) {
        return NULL;
    }
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
    return NULL;
}

void preorder(Node* tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(Node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void postorder(Node* tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

void bfs(Node* tree)
{
    if (tree == NULL) {
        return;
    }

    Queue* q = init_queue(100);
    enqueue(q, tree);
    while (!is_empty(q)) {
        Node* cur = dequeue(q);
        printf("%d ", cur->data);
        if (cur->left != NULL) {
            enqueue(q, cur->left);
        }
        if (cur->right != NULL) {
            enqueue(q, cur->right);
        }
    }
    free_queue(q);
}

void display(Node* tree, int value)
{
    if (value == 1) {
        preorder(tree);
        printf("\n");
    } else if (value == 2) {
        inorder(tree);
        printf("\n");
    } else if (value == 3) {
        postorder(tree);
        printf("\n");
    } else if (value == 4) {
        bfs(tree);
        printf("\n");
    } else if (value == 5) {
        printf("%d\n", count_nodes(tree));
    }
}

int main() {
    Node* tree = NULL;
    while (1) {
        int op;
        scanf("%d", &op);

        if (op == 0) {
            int v;
            scanf("%d", &v);
            tree = free_tree(tree);
            tree = create_node(v);
        } else if (op == 1) {
            int v;
            scanf("%d", &v);
            tree = add(tree, v);
        } else if (op == 2) {
            int v;
            scanf("%d", &v);
            display(tree, v);
        } else if (op == 3) {
            tree = free_tree(tree);
        } else if (op < 0) {
            break;
        }
    }
    tree = free_tree(tree);
    return 0;
}