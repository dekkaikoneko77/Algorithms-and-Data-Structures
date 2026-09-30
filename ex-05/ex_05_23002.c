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

Node* delete_node(Node* tree, int key) {
    if (tree == NULL) {
        return NULL;
    }
    if (key < tree->data) {
        tree->left = delete_node(tree->left, key);
    } else if (tree->data < key) {
        tree->right = delete_node(tree->right, key);
    } else {
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
        } else {
            Node* temp = find_max(tree->left);
            tree->data = temp->data;
            tree->left = delete_node(tree->left, temp->data);
        }
    }
    return tree;
}

void search(Node* tree, int value){
    if (tree == NULL) {
        printf("0\n");
        return;
    } 
    if (tree->data == value) {
        printf("1\n");
        return;
    } else if (value < tree->data) {
        search(tree->left, value);
    } else if (tree->data < value) {
        search(tree->right, value);
    }
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

void display(Node* tree, int value) {
    if (tree == NULL) { 
        printf("\n");
        return;
    } else if (value == 1) {
        preorder(tree);
        printf("\n");
    } else if (value == 2) {
        inorder(tree);
        printf("\n");
    } else if (value == 3) {
        postorder(tree);
        printf("\n");
    }
   
}

int main() {
    Node* tree = NULL;
    while(1){
        int a = 0, b = 0;
        scanf("%d", &a);
        if (a == 0) {
            scanf("%d", &b);
            tree = create_node(b);
        } else if (a == 1) {
            scanf("%d", &b);
            tree = add(tree, b);
        } else if (a == 2) {
            scanf("%d", &b);
            tree = delete_node(tree, b);
        } else if (a == 3) {
            scanf("%d", &b);
            search(tree, b);
        } else if (a == 4) {
            scanf("%d", &b);
            display(tree, b);
        } else if (a == 5) {
            tree = free_tree(tree);
        } else if (a < 0) {
            break;
        }
    }
    tree = free_tree(tree);
    return 0;
}



