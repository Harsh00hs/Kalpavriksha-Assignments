// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    char str[1000];
    scanf("%[^\n]", str);
    getchar();

    char arr[1000];
    int top=-1;
    int i=0;
    
    while(str[i]!='\0'){
        if(str[i]=='{' || str[i]=='[' || str[i]=='('){
            arr[++top]=str[i];
        }
        else if((str[i] == '}' && arr[top] == '{') || (str[i] == ']' && arr[top] == '[') || (str[i] == ')' && arr[top] == '(')){
            top--;
        }
        else{
            printf("no");
            return 0;
        }
        i++;
    }
    if(top==-1 && strlen(str)!=1 && strlen(str)!=0)
        printf("yes");
    else
        printf("no");
    
    return 0;
}