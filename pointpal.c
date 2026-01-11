#include<stdio.h>
#include<string.h>
int main(){
    printf("Enter a string (max 200 characters) to check if it is a palindrome\n");
    char str[200];
    fgets(str,sizeof(str),stdin);
    int len=strlen(str);
return 0;
}