#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_list(void) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;
    return node;
}

void append(Node* head, int value) {
    Node* node = create_node(value);
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = node;
}

void insert(Node* list, int value, int position) {
    Node* node = create_node(value);
    



}

int main(void) {
    Node* list = create_list();
    append(list, 20);
    append(list, 30);
}