#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool func(char * str){
    char alpha[26] = {};

    char temp = str[0];
    for(int i=1; i<strlen(str); i++){
        if(temp != str[i]){
            if(alpha[temp-97] != 0){
                return false;
            }else{
                alpha[temp-97] = 1;
                temp = str[i];
            }
        }
    }
    if(alpha[temp-97] != 0){
        return false;
    }
    return true;
}

int main(){
    int N;
    scanf("%d", &N);
    
    int result = 0;
    for(int i=0; i<N; i++){
        char arr[101];
        scanf("%s", arr);

        if(func(arr)){
            result+=1;
        }
    }
    printf("%d", result);
}