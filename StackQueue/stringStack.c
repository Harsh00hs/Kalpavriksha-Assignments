#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define maxLen 100
#define max 10

typedef struct stack{
    char str[max][maxLen];
    int top;
}stack;

void initStack(stack* s){
    s->top=-1;
}

void push(stack* s, char word[]){
    if(s->top==max-1){
        printf("Overflow\n");
        return;
    }
    // char *temp=strdup(word);
    
    strcpy(s->str[++s->top], word);
}

void pop(stack* s){
    if(s->top==-1){
        printf("Underflow\n");
        return;
    }
    printf("Popping: %s\n", s->str[s->top--]);
}

void peek(stack* s){
    if(s->top==-1){
        printf("Underflow\n");
        return;
    }
    printf("Words on top: %s\n", s->str[s->top]);
}

void display(stack* s){
    if(s->top==-1){
        printf("Nothing to display\n");
        return;
    }
    for(int i=s->top; i>=0; i--){
        printf("%s\n", s->str[i]);
    }
}
void longestString(stack* s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return;
    }
    int len=strlen(s->str[0]);
    int sss=0;
    for(int i=1; i<=s->top; i++){
        if(strlen(s->str[i])>len){
            len=strlen(s->str[i]);
            sss=i;
        }
    }
    printf("Longest string is %s with lenght: %d\n", s->str[sss], len);
}

int main(){
    stack s;
    initStack(&s);
    
    int op;
    printf("Enter operations: ");
    scanf("%d", &op);
    while(op<1 || op>100){
        printf("Print between (1 - 100): ");
        scanf("%d", &op);
    }
    
    int ch;
    char words[maxLen];
    
    while(op--){
        printf("Stack Menu:\n");
        printf("\t\t\t1.Push\n");
        printf("\t\t\t2.Pop\n");
        printf("\t\t\t3.Peek\n");
        printf("\t\t\t4.Display\n");
        printf("\t\t\t5.Longest Words\n");
        printf("Enter The Choice: ");
        scanf("%d", &ch);
        getchar();
        switch(ch){
            case 1:
                printf("enter word: ");
                scanf("%[^\n]", words);
                push(&s, words);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                longestString(&s);
                break;
                
            default:
                printf("invalid\n");
                break;
        }
    }
    
    return 0;
}