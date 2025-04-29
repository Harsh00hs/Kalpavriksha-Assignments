// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%[^\n]", str);
    getchar();
    char sub[100];
    scanf("%[^\n]", sub);
    
    int ans = -1;
    for (int i = 0; i < strlen(str); i++) {
        int match = 1;
        for (int j = 0; j < strlen(sub); j++) {
            if (str[i + j] != sub[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            ans = i;
            break;
        }
    }

    printf("%d", ans);
    return 0;
}