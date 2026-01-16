#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    printf("enter a string of alphabets in alphabetical order: ");
    char str[20];
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        str[i]=(char)((int)str[i]+3);
    }
    printf("The result is: %s ", str);
    return 0;
}