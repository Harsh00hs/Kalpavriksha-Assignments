#include "stdio.h"
#include "string.h"

int isOperand(char c){
    return ((c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z'));
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void inToPost(char str[]){
    int len=strlen(str);
    char result[len+1];
    char stack[len];
    int top=-1;
    int j=0; //result index
    
    for(int i=0; i<len; i++){
        if(isOperand(str[i]))
            result[j++]=str[i];
        
        else if(str[i]=='(')
            stack[++top]=str[i];

        else if(str[i]==')'){
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            top--; 
        }
        
        else {
            while (top != -1 && (prec(str[i]) < prec(stack[top]) || prec(str[i]) == prec(stack[top]))) {
                result[j++] = stack[top--];
            }
            stack[++top] = str[i];
        }
    }

    while (top != -1) {
        result[j++] = stack[top--];
    }

    result[j] = '\0';
    printf("%s\n", result);
}

int main(){
    char str[]= "a+(b*c)-d";
    inToPost(str);
    return 0;
}