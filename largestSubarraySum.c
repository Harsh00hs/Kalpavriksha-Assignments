#include <stdio.h>
#include "stdlib.h"

int main() {
    int* arr;
    int n;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    arr=(int*)malloc(n * sizeof(int));
    
    if(arr == NULL){
        printf("Memory not allocated.\n");
        return 1;
    }else{
        printf("Memory allocated.\n");
        for (int j = 0; j < n; ++j) { 
            scanf("%d", &arr[j]);
        }
    }
    
    int maxSum=arr[0];
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(maxSum<sum)
                maxSum=sum;
        }
    }
    printf("%d", maxSum);
    
    free(arr);
    return 0;
}
