#include <stdio.h>
#include <string.h>

void rremove(char *s){
    int n = strlen(s);
    char str[101] = "";
    int k = 0;

    for (int i = 0; i < n; i++){
        int repeated = 0;

        while (i + 1 < n && s[i] == s[i + 1]){
            repeated = 1;
            i++;
        }

        if (!repeated)
            str[k++] = s[i];
    }

    str[k] = '\0';
    if (n == k)
        strcpy(s, str);
    else{
        strcpy(s, str);
        rremove(s);
    }
}

int main(){
    char s[100];
    scanf("%[^\n]", s);
    rremove(s);
    printf("%s", s);

    return 0;
}
