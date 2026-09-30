void sort3elements(int D[], int a, int b, int c) {
    if (D[b] < D[a]) {
        swap(&D[a], &D[b]);
    }
    if (D[c] < D[b]) {
        swap(&D[b], &D[c]);
    }
    if (D[b] < D[a]) {
        swap(&D[a], &D[b]);
    }
}

int partition(int D[], int left, int right) {
    int mid = (left + right) / 2;
    // 先頭/中央/末尾の中央値を取得
    sort3elements(D, left, (left + right) / 2, right);

    // ソート済みの手前とピボットを交換
    swap(&D[], &D[]);
    // ピボット
    int pivot = D[];

    // 走査範囲
    int i = ;
    int j = ;
    while (i <= j) {
        // 省略
    }
    // ピボットを分割点に置く
    swap(&D[], &D[]);

    return i;
}

// クイックソートの関数
void quicksort(int D[], int left, int right) {
    if (right - left == 1) {  // 要素数が2のときの処理
        if (D[right] < D[left]) {
            swap(&D[left], &D[right]);
        }
    } else {  // 要素数3以上のとき
        int i = partition(D, left, right);
        if (left < i - 1) {
            quicksort(D, left, i - 1);
        }
        if (i + 1 < right) {
            quicksort(D, i + 1, right);
        }
    }
}
