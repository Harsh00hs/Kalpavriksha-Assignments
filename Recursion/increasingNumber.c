#include "stdio.h"

// void increasingNumber(int x, int n){
//     if(x>n) return;
//     printf("%d\n", x);
//     increasingNumber(x+1, n);
//     return;
// }

void increasingNumber(int n){
    if(n==0) return; //base case
    // printf("%d\n", n); //code
    increasingNumber(n-1); //call
    printf("%d\n", n); //code
    return;
}


int main(){
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    printf("Increasing Number from 1 to %d\n", n);

    // increasingNumber(1, n);

    increasingNumber(n);

    return 0;
}