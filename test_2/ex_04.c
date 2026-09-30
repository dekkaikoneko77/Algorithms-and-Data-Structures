int str_to_int(char str[]) {
    int x = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        x = x + str[i];
    }
    return x;
}

// ハッシュ関数
int hash(int x) {
    return x % 11;
}

// 再ハッシュ先を求める関数
int rehash(int k) {
    return (k + 1) % 11;
}

// データを挿入
void insert(int h[], char str[]) {
    // 文字列を整数値に変換
    int x = str_to_int(str);
    // ハッシュ値を求める
    int k = hash(x);

    for (int i = 0; i < 11; i++) {
        // 省略
    }
}

// ハッシュ表の内容を表示
void print(int h[]) {
    printf("table\n");
    for (int i = 0; i < 11; i++) {
        printf("%d\n", h[i]);
    }
    printf("---\n");
}

int main(void) {
    char str[1000];
    int x = 0, h[1000] = 0;
    scanf("%d", x);
    for (int i = 0; i < x; i++){
        for (int j)
    }
    
}
