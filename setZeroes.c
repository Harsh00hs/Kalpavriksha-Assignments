#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to mark all elements in the given row as -1 except 0
void markRow(int matrix[MAX_ROWS][MAX_COLS], int n, int m, int i) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

// Function to mark all elements in the given column as -1 except 0
void markCol(int matrix[MAX_ROWS][MAX_COLS], int n, int m, int j) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

// Function to apply the zeroing logic to the matrix
void zeroMatrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {
    // Mark rows and columns that should be zeroed
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i); // Mark row
                markCol(matrix, n, m, j); // Mark column
            }
        }
    }

    // Final pass: Convert all -1 back to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int n;
    int m;

    for(int i=0;)

    printf("Original Matrix:\n");
    printMatrix(matrix, n, m);
    
    // Apply zeroMatrix function
    zeroMatrix(matrix, n, m);

    printf("\nMatrix after applying zeroMatrix:\n");
    printMatrix(matrix, n, m);

    return 0;
}
