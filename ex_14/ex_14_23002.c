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
        for (int i = j; i < n / 3; i++) {
            w1 += w[i];      
            w2 += w[i + 3];  
            w3 += w[i + 6];  
        }
        if (w1 > w2) {
            if (w1 == 0) {
                printf("%d\n", n);
                break;
            } else {
                n = n / 3;
            }
        } else if (w2 > w1) {
            if (w2 == 0) {
                printf("%d\n", n);
                break;
            } else {
                j = n / 3;
                n = 2 * n / 3;
            }
        } else {
            if (w3 == 0) {
                printf("%d\n", n);
                break;
            } else {
                j = 2 * n / 3;
            }
        }
    }
    

}
