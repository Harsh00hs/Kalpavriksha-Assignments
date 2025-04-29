#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }

    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int num;
    scanf("%d", &num);
    
    printf("Sum of digits of %d is: %d\n", num, sumOfDigits(num));
    
    return 0;
}
