#include <stdio.h>
#include "stdlib.h"

int main() {
    int* arr;
    int n;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    arr=(int*)malloc(n * sizeof(int));
    
    if(arr == NULL)
        printf("Memory not allocated.\n");
    else{
        printf("Memory allocated.\n");
        for (int j = 0; j < n; ++j) { 
            scanf("%d", &arr[j]);
        } 
        // printf("The elements of the array are: "); 
        // for (int k = 0; k < n; ++k) { 
        //     printf("%d, ", arr[k]); 
        // }
    }    
    int k;
    printf("Enter the target value: ");
    scanf("%d", &k);
    
    int count=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(k==sum){
                printf("Subarray: [");
                for(int l=i; l<=j; l++){
                    printf("%d", arr[l]);
                    if(l!=j)
                        printf(", ");
                }
                printf("]");
                printf("\n");
                count++;
            }
        }
    }
    
    printf("Subarrays Count: %d", count);
    free(arr);
    return 0;
}
