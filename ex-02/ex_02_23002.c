#include <stdio.h>
#include <stdlib.h>

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
    while (last -> next != NULL) {
        last = last -> next;
    }
    last -> next = node;
}

void insert(Node* list, int value, int position) {
    Node* node = create_node(value);
    Node* current = list;

    for (int i = 0; i < position - 1; i++) {
        current = current -> next;
    }

    node -> next = current -> next;
    current -> next = node;

}

void delete_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current -> next;
        free(temp);
    }
}

void delete_node(Node* list, int position) {
    Node* current = list;
    for (int i = 0; i < position - 1; i++) {
        current = current -> next;
    }
    Node* temp = current -> next;
    current -> next = temp -> next;
    free(temp);
}

void print_data(Node* head) {
    Node* current = head -> next; // Skip the dummy head node
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("\n");
}

void print_addresses(Node* head) {
    Node* current = head->next; // Skip the dummy head node
    while (current != NULL) {
        printf("%p -> ", (void*)current);
        current = current->next;
    }
    printf("NULL\n");
}

int a = 0, b = 0, c = 0;

int main(void) {
    Node* list = create_list();
    while (1) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            append(list, b);

        } else if (a == 2){
            scanf("%d", &b);
            insert(list, b, 1);

        } else if (a == 3) {
            scanf("%d", &b);
            scanf("%d", &c);
            insert(list, b, c);

        } else if (a == 4) {
            scanf("%d", &b);
            delete_node(list, b);
            
        } else if (a == 5) {
            print_data(list);
            print_addresses(list);
            
        } else if (a < 0) {
            delete_list(list);
            break;
       }
        //print_data(list);
        //print_addresses(list);
    }

    // return 0;

}