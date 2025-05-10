#include <stdio.h>

long long modularExponentiation(long long base, long long expo, long long mod) {
    long long result = 1;
    if (base == 0) 
        return 0;
    base = base % mod;

    while (expo > 0) {
        if (expo % 2 == 1) {
            result = (result * base) % mod;
        }
        expo = expo / 2;
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long a, n, mod;

    printf("Enter base: ");
    if (scanf("%lld", &a) != 1 || a < 0) {
        printf("Error: Base must be a non-negative integer.\n");
        return 1;
    }

    printf("Enter exponent: ");
    if (scanf("%lld", &n) != 1 || n < 0) {
        printf("Error: Exponent must be a non-negative integer.\n");
        return 1;
    }

    printf("Enter modulus: ");
    if (scanf("%lld", &mod) != 1 || mod <= 0) {
        printf("Error: Modulus must be a positive integer.\n");
        return 1;
    }

    long long result = modularExponentiation(a, n, mod);
    printf("Result: %lld\n", result);

    return 0;
}