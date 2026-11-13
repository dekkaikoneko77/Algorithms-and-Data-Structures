#include <stdio.h>

int BB_subsetsum(int level, int n, int s, int x[], int y[]) {
    int found = 0;

    if (level > n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += y[i] * x[i];
        }
        if (sum == s) { 
            found = 1;
        }
    } else {
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i = i + 1) {
            if (i<level) {
                sum1 = sum1 + y[i] * x[i];
                sum2 = sum1;
            } else {
                sum2 = sum2 + x[i];
            }
        }
        if ((sum1 <= s) && (sum2 >= s)) { //枝刈りの判定
            y[level] = 0;
            found = BT_subsetsum(level + 1, n, s, x, y);
            if (!found) {
                // 解が見つかっていなければもう片方の選択を探索
                y[level] = 1;
                found = BT_subsetsum(level + 1, n, s, x, y);
            }
        }
    }
    return found;
}

int main() {
    int n, s;
    int x[11], y[11]; // 荷物は1番から使う
    int i;

    scanf("%d %d", &n, &s);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        y[i] = 0; // 初期化
    }

    if (BB_subsetsum(1, n, s, x, y)) {
        printf("sに等しい選び方が存在する\n");
    } else {
        printf("sに等しい選び方が存在しない\n");
    }

    return 0;

}