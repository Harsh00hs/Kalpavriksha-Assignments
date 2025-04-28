#include "stdio.h"

void insertionSort(int arr[100], int n){
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && key < arr[j]){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[100];
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, n);

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}