#include "stdio.h"

void decreasingNumber(int n){
    if(n==0) return;
    printf("%d\n", n);
    decreasingNumber(n-1);
    return;
}

int main(){
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    printf("Decreasing Number from %d to 1\n", n);

    decreasingNumber(n);
}