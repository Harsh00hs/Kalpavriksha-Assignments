#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int getRowLenght(char input[100]) {
    int t = 0;
    int row = 0;
    while (input[t] != '\0') {
        if (input[t] == ']') {
            row++;
            t++;
        } else {
            t++;
        }
    }
    
    return row - 1;
}

int getCoulmnLength(char input[100]) {
    int t = 0, count = 0;
    int inside_first_bracket = 0;

    while (input[t] != '\0') {
        if (input[t] == '[' && inside_first_bracket == 0) {
            inside_first_bracket = 1;
            t++;
            continue;
        }

        if (inside_first_bracket == 1) {
            if (isDigit(input[t])) {
                count++;
                
                while (isDigit(input[t])) {
                    t++;
                }
            }
            
            if (input[t] == ']') {
                break;
            }
        }
        t++; 
    }
   
    return count;
}

int main() {
    char input[100];
    scanf("%[^\n]", input);
    
    int row = getRowLenght(input);
    int col = getCoulmnLength(input);
    
    int **matrix = calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = calloc(col, sizeof(int));
    }

    int row_index = 0;
    int col_index = 0;
    int t = 0;
    int negative_value = 0;
    int temp = 0;
    while (input[t] != '\0') {
        if (input[t] == '-') {
            negative_value = 1;
        }
        if (isDigit(input[t])) {
            temp = temp * 10 + (input[t] - '0');
        } else if (input[t] == ' ' || input[t] == ',' || input[t] == ']') {
            if (temp > 0 || input[t - 1] == '0') { 
                if (negative_value == 1) {
                    temp = -temp;
                    negative_value = 0;
                }
                matrix[row_index][col_index++] = temp;
                temp = 0;
            }
        } else if (input[t] == '[') {
            if (col_index > 0) {
                col_index = 0;
                row_index++;
            }
        }
        t++;
    }

    int top = 0;
    int left = 0;
    int right = col - 1;
    int bottom = row - 1;
    
    printf("[");
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            if (i == 0 && top == 0) {
                printf("%d", matrix[top][i]);
            } else {
                printf(" %d", matrix[top][i]);
            }
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            printf(" %d", matrix[i][right]);
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf(" %d", matrix[bottom][i]);
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf(" %d", matrix[i][left]);
            }
            left++;
        }
    }
    printf("]");

    return 0;
}