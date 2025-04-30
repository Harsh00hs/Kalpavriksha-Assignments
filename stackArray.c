// Online C compiler to run C program online
#include <stdio.h>
#define maxSize 100

int top=-1;

void push(int n, int arr[maxSize]){
    if(top==n-1){
        printf("Overflowed\n");
        return;
    }
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    
    top++;
    arr[top]=val;
}

void pop(int arr[maxSize]){
    if(top==-1){
        printf("Underflowed\n");
        return;
    }
    printf("Popped Element: %d\n", arr[top]);
    top--;
}

void peek(int arr[maxSize]){
    if(top==-1){
        printf("Stack is empty.\n");
        return;
    }
    for(int i=0; i<=top; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[maxSize];
    int n;
    
    printf("Enter the size of array stack: ");
    scanf("%d", &n);
    
    int ch;
    
    printf("Choices :-\n\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Exit");
    
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                push(n, arr);
                break;
            case 2:
                pop(arr);
                break;
            case 3:
                peek(arr);
                break;
            case 4:
                return 0;
            default:
                printf("Check the choices given nothing else.");
                return 0;
        }
    }

    return 0;
}
