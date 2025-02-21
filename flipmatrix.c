#include "stdio.h"

int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    int matrix[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sum=0;
    for(int i=0; i<r; i++){
        int max=matrix[i][0];
        for(int j=0; j<c; j++){
            if(max<matrix[i][j]){
                max=matrix[i][j];
            }
        }
        sum+=max;
    }

    printf("%d", sum);

    return 0;
}