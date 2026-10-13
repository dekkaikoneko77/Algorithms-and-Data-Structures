#include <stdio.h>

int main() {
    int w[9];
    for (int i = 0; i < 9; i++) {
        scanf("%d", &w[i]);
    }

    int j = 0,n = 9;
    int w1 = 0, w2 = 0, w3 = 0;

    for (int k = 0; k < 2; k++) {
        w1 = 0, w2 = 0, w3 = 0;

        int groupSize = n / 3;

        for (int i = 0; i < groupSize; i++) {
            w1 += w[j + i];
            w2 += w[j + groupSize + i];
            w3 += w[j + 2 * groupSize + i];
        }

        if (w1 > w2) {
            j += groupSize;
            n = groupSize;
        } else if (w2 > w1) {
            n = groupSize;
        } else {
            j += 2 * groupSize;
            n = groupSize;
        }
    }

    printf("%d\n", j + 1);
    return 0;
}