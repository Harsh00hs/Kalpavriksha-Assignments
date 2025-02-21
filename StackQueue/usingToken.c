#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#define max 100
#define maxLen 1000

int top=-1;

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

int isnum(char c){
    return (c>='0' && c<='9');
}

int parseToInteger(char str[]) {
    int i = 0, temp = 0, sign = 1;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (isnum(str[i])) {
            temp = temp * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }

    return sign * temp;
}


int main(){
    int arr[max];
    int n;
    
    scanf("%d", &n);
    getchar();
    
    char str[maxLen];
    int page;
    
    while(n--){
        scanf("%[^\n]", str);
        getchar();

        char *token=strtok(str," ");
        
        if(strcmp(token, "BOOKMARK")==0){
            token=strtok(NULL, " ");
            page=parseToInteger(token);
            bookmark(arr, page);
        }
        else if(strcmp(token, "DELETE")==0){
            delete(arr);
        }
        else if(strcmp(token, "LIST")==0){
            list(arr);
        }
        else{
            printf("Invalid\n");
        }
        
    }
    
    return 0;
}