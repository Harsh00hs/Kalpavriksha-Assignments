#include <stdio.h>
#include "stdlib.h"
#define max 100

int top = -1;

int isFull(){
    return (top==max-1);
}

int isEmpty(){
    return(top==-1);
}

void bookmark(int arr[], int val){
    if(isFull()){
        printf("bookmarks full\n");
    }else{
        arr[++top]=val;
    }
}

void delete(int arr[]){
    if(isEmpty()){
        printf("no bookmarks\n");
    }else{
        printf("%d\n", arr[top--]);
    }
}

void list(int arr[]){
    if(isEmpty()){
        printf("no bookmarks\n");
    }else{
        int temp[top+1];
        for(int i=0; i<=top; i++)
            temp[i]=arr[i];
        
        for(int i=0; i<top; i++){
            for(int j=i+1; j<=top; j++){
                if(temp[i]>temp[j]){
                    int tmp=temp[i];
                    temp[i]=temp[j];
                    temp[j]=tmp;
                }
            }
        }
        
        for(int i=0; i<=top; i++)
            printf("%d ", temp[i]);
        printf("\n");
    }
}

int main() {
    int arr[max];
    int n;
    
    scanf("%d", &n);
    
    int ch;
    int val;
    
    while(n--!=0){
        scanf("%d", &ch);
        switch(ch){
            case 1:
                scanf("%d", &val);
                if(val<1 || val>1000){
                    printf("Invalid\n");
                    break;
                }
                
                bookmark(arr, val);
                break;
            case 2:
                delete(arr);
                break;
            case 3:
                list(arr);
                break;
            default:
                printf("Invalid\n");
                break;
        }
    }

    return 0;
}