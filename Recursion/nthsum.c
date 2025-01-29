#include "stdio.h"

// void sum(int n, int s){
//     if(n==0){
//         printf("Sum: %d", s);
//         return;
//     }
//     sum(n-1, s+n);
//     return;
// }

int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}

int main(){
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    printf("Sum of 1 to %d\n", n);

    // sum(n, 0);

    printf("%d", sum(n));

    return 0;
}