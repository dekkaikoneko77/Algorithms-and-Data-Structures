#include <stdio.h>

void search(int data[],int key,int x){
    int t;
    if(x%2 == 1) {
        int t = x/2;        
    } else {
        int t = x/2 - 1;
    }
    if(data[t] == key) {
        printf("%d", t);
    } else if(data[t] > key) {
        printf("%d %d %d", 0, x-1, t);
        while (data[t] != key) {
            int tmp = t;
            t = t/2;
            if(data[t] == key) {
                printf("%d", t);
                break;
            } else if(data[t] > key) {
                printf("%d %d %d", 0, tmp-1, t);
            } else {
                printf("%d %d %d", tmp+1, tmp, t);
            }
        }        
    } else {
        printf("%d %d %d", 0, x-1, t);
        while (data[t] != key) {
            int tmp = t;
            t = (t+x)/2;
            if(data[t] == key) {
                printf("%d", t);
                break;
            } else if(data[t] > key) {
                printf("%d %d %d", tmp+1, x-1, t);
            } else {
                printf("%d %d %d", 0, tmp-1, t);
            }
        }
    }
}

int main() {
    int data[10000];
    int x,k;
    scanf("%d",&x);
    for(int i = 0; i < x; i++) {
        scanf("%d ",data[i]);
    }
    scanf("%d",&k);
    search(data, k, x);

}