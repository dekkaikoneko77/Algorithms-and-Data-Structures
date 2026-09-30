// 木のノードの構造体
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node** data;  // データ配列
    int max;      // 最大容量
    int head;     // 先頭位置（取り出し位置）
    int tail;     // 末尾位置（次に追加する位置）
    int size;     // 現在の要素数
} Queue;

// 初期化
Queue* init_queue(int max);

// 空か確認
int is_empty(Queue* queue);

// 満杯か確認
int is_full(Queue* queue);

// enqueue
void enqueue(Queue* queue, Node* value);

// dequeue
Node* dequeue(Queue* queue);

// 解放
void free_queue(Queue* queue);

// クリア
void clear(Queue* queue);
