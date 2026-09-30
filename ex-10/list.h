// ノードの構造体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 新しいリストを作成する関数
Node *create_list(void);

// 新しいノードを作成する関数
Node *create_node(int value);

// リストの末尾に新しいノードを追加する関数
void append_node(Node* head, int position);

// リストの任意の値を探して削除する関数
void delete_node(Node* list, int value);

// リストから値を探索する関数
int search_value(Node *list, int value);

// リストを削除してメモリを解放する関数
Node *delete_list(Node* head);

// リストの内容を表示する関数
void print_list(Node* head);
