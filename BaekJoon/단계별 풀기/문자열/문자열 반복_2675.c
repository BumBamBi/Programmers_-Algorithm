#include<stdio.h>
#include<string.h>

int main(){
    int T;
    scanf("%d", &T);

    int R[1000];
    char S[1000][21];

    for(int i=0; i<T; i++){
        scanf("%d", &R[i]);

        scanf("%s", S[i]);
    }
    
    for(int i=0; i<T; i++){
        for(int j=0; j<strlen(S[i]); j++){
            for(int k=0; k<R[i]; k++){
                printf("%c",S[i][j]);
            }
        }
        printf("\n");
    }
}