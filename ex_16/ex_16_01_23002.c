#include <stdio.h>

int BB_subsetsum(int level, int n, int s, int x[], int y[]) {
    int found = 0;

    if (level > n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
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
        if ((sum1 <= s) && (sum2 >= s)) { //}Š ‚è‚Ì”»’è
            y[level] = 0;
            found = BB_subsetsum(level + 1, n, s, x, y);
            if (!found) {
                // ‰ğ‚ªŒ©‚Â‚©‚Á‚Ä‚¢‚È‚¯‚ê‚Î‚à‚¤•Ğ•û‚Ì‘I‘ğ‚ğ’Tõ
                y[level] = 1;
                found = BB_subsetsum(level + 1, n, s, x, y);
            }
        }
    }
    return found;
}

int main() {
    int n, s;
    int x[11], y[11]; // ‰×•¨‚Í1”Ô‚©‚çg‚¤
    int i;

    scanf("%d %d", &s, &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        y[i] = 0; // ‰Šú‰»
    }

    if (BB_subsetsum(1, n, s, x, y)) {
        for (i = 1; i <= n; i++) {
            if (y[i] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    } else {
        printf("s‚É“™‚µ‚¢‘I‚Ñ•û‚ª‘¶İ‚µ‚È‚¢\n");
    }

    return 0;
}