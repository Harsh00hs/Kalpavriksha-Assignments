#include "stdio.h"

int main(){
    int r, c;
    printf("Enter rows and cols for the first matrix (r x c) and it will be row of second matrix too:  ");
    scanf("%d%d", &r, &c);

    int c2;
    printf("Enter the number of cols for the second matrix (c x c2): ");
    scanf("%d", &c2);

    printf("Order of first matrix: %d, %d \n", r, c);
    printf("Order of second matrix: %d, %d \n", c, c2);

    int a[r][c], b[c][c2], mul[r][c2];


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter the value of matrix 1 (%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Enter the value of matrix 2 (%d, %d): ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("The value of matrix 1: \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("The value of matrix 2: \n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < c; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The matrix multiplication is: \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}