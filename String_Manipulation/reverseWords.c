#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *tokens[50]; // Array to hold pointers to words (tokens)
    int i = 0;

    // Input string
    printf("Enter a string: ");
    scanf("%[^\n]", &str);
    
    str[strcspn(str, "\n")] = '\0';
    
    char *token = strtok(str, " ");
    
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " "); // Get the next token
    }

    // Print the tokens in reverse order
    printf("Reversed words: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%s", tokens[j]);
        if (j != 0) {
            printf(" "); // Add space between words
        }
    }
    printf("\n");

    return 0;
}
