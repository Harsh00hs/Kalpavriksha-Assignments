#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#define maxRows 10
#define maxCols 100
#define maxLength 50

int main() {
    int r, c;
    char words[maxRows][maxCols][maxLength];
    char longestWord[maxLength]= " ";
    char secondLongest[maxLength]= " ";
    do{
        printf("Enter number of rows(1-10): ");
        if(scanf("%d", &r) !=1) return 0;
    }while((r<0 || r>10));
    
    do{
        printf("Enter number of cols(1-100): ");
        if(scanf("%d", &c) !=1) return 0;
    }while(c<0 || c>101);
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("Enter word at (%d, %d): ", i, j);
            scanf("%s", &words[i][j]);
            
            if(strlen(words[i][j]) > strlen(longestWord))
                strcpy(longestWord, words[i][j]);
        }
    }
    
    printf("\nLongest Word: %s\n", longestWord);
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if((strlen(words[i][j]) < strlen(longestWord)) && (strlen(words[i][j]) > strlen(secondLongest)))
                strcpy(secondLongest, words[i][j]);
        }
    }
    
    printf("\nSecond Longest word: %s\n", secondLongest);
    
    return 0;
}
