#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char str[], int start, int end) {
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++) {
            swap(&str[start], &str[i]);
            permutation(str, start + 1, end);
            swap(&str[start], &str[i]);
        }
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    int n = strlen(str);

    printf("Permutations of the string %s are:\n", str);
    permutation(str, 0, n - 1);

    return 0;
}
