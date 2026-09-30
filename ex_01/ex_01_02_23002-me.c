#include <stdio.h>

int sum(int arr[], int start, int end) {
    int sum = 0;
    for(int i = start; i < end; i++) {
        sum += arr[i];
    }

    return sum;

}


int main(void) {
    int i;

    scanf("%d", &i);
    int deta[i];

    for(int j = 0; j < i; j++) {
        scanf("%d", &deta[j]);
    }

    printf("\n");

    int start = 0;
    int end = i;

    int sarhi_end = i;

    while(1) {
        int sum_deta = sum(deta, start, end);
        printf("%d\n", sum_deta);
        if(end - start == 1) {
            printf("%d\n", end);
            break;
        } else if(sum_deta % 100 == 0) {
            start = end;            
            end = sarhi_end;
            //printf("%d %d\n", start, end);
        } else if(sum_deta % 100 != 0){
            end = start + (end - start) / 2;  
            //printf("%d %d\n", start, end);      
        }
    }

    
    
}

