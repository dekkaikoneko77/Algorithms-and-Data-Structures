typedef struct {
    // スタックのデータを格納する配列の先頭アドレス
    int *data;
    // スタックの最大容量
    int max;
    // スタックポインタ
    int sp;
} Stack;

// 初期化
Stack *init_stack(int max);
// 空か確認
int is_empty(Stack *stack);
// 満杯か確認
int is_full(Stack *s);
// push
void push(Stack *stack, int value);
// pop
int pop(Stack *stack);
// スタックの先頭要素を確認
int peek(Stack *stack);
// 解放
void free_stack(Stack *stack);
// スタックを空にする
void clear(Stack *stack);
// 探索
int search(Stack *stack, int value);
