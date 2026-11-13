#include <stdio.h>

BB_subsetsum(int level, int n, int s, int x[], int y[]) {
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

    if (level == 1) {
        printf("sに等しい選び方が存在しない\n");
    }
}

int main() {

}