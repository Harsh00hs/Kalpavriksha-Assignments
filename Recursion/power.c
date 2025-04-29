#include "stdio.h"

int power(int n, int p){
    if(p==0) return 1;
    return n*power(n, p-1);
}

int main(){
    int n, pow;

    printf("Enter Number: ");
    scanf("%d", &n);

    printf("Enter Power: ");
    scanf("%d", &pow);

    printf("Power of %d^%d: %d\n", n, pow, power(n, pow));

    return 0;
}