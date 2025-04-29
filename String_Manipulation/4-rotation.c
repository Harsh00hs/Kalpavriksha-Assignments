// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int rotated(char *str, char *rot, int n){
    if(n != strlen(rot))
        return 0;
    
    char join[2*n+1];
    
    for(int i=0; i<2*n; i++){
        join[i] = str[i];
        join[n+i] = str[i];
    }
    join[2*n] = '\0';
    
    for(int i=0; i<2*n; i++){
        int match=1;
        for(int j=0; j<n; j++){
            if(join[i+j]!=rot[j]){
                match=0;
                break;
            }
        }
        if(match) 
            return 1;
    }
    return 0;
}

int main() {
    char str[100];
    scanf("%s", str);
    getchar();
    char rot[100];
    scanf("%s", rot);
    
    int n=strlen(str);
    
    if(rotated(str, rot, n))
        printf("True");
    else
        printf("False");
    
    return 0;
}