#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char arr[100] = {};
    scanf("%s", arr);

    int result = 0;
    for(int i=0; i<strlen(arr); i++){
        int temp = arr[i]-48;
        result += temp;
    }
    printf("%d", result);
}