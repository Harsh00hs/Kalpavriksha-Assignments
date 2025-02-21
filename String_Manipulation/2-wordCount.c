// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%[^\n]", str);
    int count=0;
    int i=0;
    
    while(str[i] == ' '){
        i++;
    }
    
    for(; i<strlen(str); i++){
        if(str[i] != ' ' && (i==0 || str[i-1] == ' ')){
            count++;
        }
    }
    
    printf("%d", count);

    return 0;
}