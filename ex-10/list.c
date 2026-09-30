#include "list.h"

#include <stdio.h>
#include <stdlib.h>

// 新しいノードを作成する関数
Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// リストの末尾に新しいノードを追加する関数
void append_node(Node* list, int value) {
    // リストの最後のノードまで移動
    Node* last = list;
    while (last->next != NULL) {
        last = last->next;
    }
    // 新しいノードを作成
    Node* node = create_node(value);
    // 最後のノードの次に新しいノードのポインタを追加
    last->next = node;
}

// リストの任意の値を探して削除する関数
void delete_node(Node* list, int value) {
    Node* prev = list;
    Node* current = list->next;
    while (current != NULL) {
        if (current->data == value) {
            // 次のノードへつなぎ替え
            prev->next = current->next;
            // メモリを解放
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

// リストから値を探索する関数
int search_value(Node* list, int value) {
    Node* current = list->next;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// リストを削除してメモリを解放する関数
Node* delete_list(Node* list) {
    Node* node = list;
    Node* next_node;

    while (node != NULL) {
        // 次のノードをあらかじめメモ
        next_node = node->next;
        // 現在のノードのメモリを解放
        free(node);
        // 次のノードへ移動
        node = next_node;
    }
    return NULL;
}

// リストの内容を表示する関数
void print_list(Node* list) {
    Node* node = list->next;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
