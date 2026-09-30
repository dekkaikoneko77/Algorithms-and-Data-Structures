#include <stdio.h>

int main(void) {
    int number;
    scanf("%d", &number);

    int sum = 0;
    
    for(int i = number; i > 0; i = i / 10) {
        sum += (i % 10);        
    }

    printf("%d\n", sum);

    if(sum % 3 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
}