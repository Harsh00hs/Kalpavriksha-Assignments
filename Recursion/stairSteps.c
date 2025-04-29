#include<stdio.h>

int stair(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;  //for 3 steps

    // int totalways= stair(n-1) + stair(n-2);
    int totalways= stair(n-1) + stair(n-2) + stair(n-3);  //for 3 steps
    return totalways;
}

int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d", &n);

    printf("Ways for %d steps is %d", n, stair(n));
    return 0;
}