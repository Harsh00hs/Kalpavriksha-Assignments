#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to apply the zeroing logic to the matrix
void diagonalreverse(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=matrix[i][i];
        if(i!=n-i-1)
            sum+=matrix[i][n-i-1];
    }
    for(int i=0; i<n; i++){
            int temp=matrix[i][i];
            matrix[i][i]=matrix[i][n-i-1];
            matrix[i][n-i-1]=temp;
    }
    printf("Sum of Diagonal: %d",sum);
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
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    printf("Original Matrix:\n");
    printMatrix(matrix, n, m);
    
    // Apply zeroMatrix function
    diagonalreverse(matrix, n, m);

    printf("\nMatrix after applying diagonalreverse:\n");
    printMatrix(matrix, n, m);

    return 0;
}
