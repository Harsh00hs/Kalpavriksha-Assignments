// Online C compiler to run C program online
#include <stdio.h>
#include "string.h"

void sort(char *str){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){
            if(str[i]>str[j]){
                char temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
}

int areAnagrams(char *a, char *b){
    // +1 for \0 terminator
    char str1[strlen(a)+1];
    char str2[strlen(b)+1];
    
    strcpy(str1, a);
    strcpy(str2, b);
    
    sort(str1);
    sort(str2);
    
    return strcmp(str1, str2) == 0;
}

void groupAnagrams(char str[][100], int n){
    int grp[n];
    for(int i=0; i<n; i++)
        grp[i]=-1;
    
    int grpcount=0;
    
    for(int i=0; i<n; i++){
        if(grp[i] != -1) 
            continue;
        printf("Group %d: ", ++grpcount);
        
        for(int j=i; j<n; j++){
            if(grp[j] == -1 && areAnagrams(str[i], str[j])){
                grp[j]= grpcount;
                printf("\"%s\" ", str[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    
    char str[n][100];
    
    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
    }
    
    printf("Grouped Anagrams: \n");
    groupAnagrams(str, n);
    
    // for(int i=0; i<n; i++){
    //     sort(str[i]);
    //     printf("%s ", str[i]);
    // }
    

    return 0;
}
