// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int isnum(char c){
    return (c >= '0' && c <= '9');
}

int main() {
    char str[100];
    scanf("%s", str);
    
    int num=0;
    int i=0;
    int negative=0;
    int valid=1;
    
    if (str[i] == '-') {
        negative = 1;
        i++;
    }
    
    while(str[i] != '\0'){
        if(!isnum(str[i])){
            valid=0;
            break;
        }
        num = num * 10 + (str[i] - '0');
        i++;
    }
    
    if (!valid || (i == 1 && negative)) {
        num = 0;
    } else if (negative) {
        num = -num;
    }

    printf("%d\n", num);
    
    return 0;
}