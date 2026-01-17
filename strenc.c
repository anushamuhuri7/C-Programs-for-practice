#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    printf("enter a string of alphabets in alphabetical order(short hand): ");
    char str[20];
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='a'&&str[i<='z']){
        str[i]='a'+(str[i]-'a'+3)%26;/*edit: for example str[i]='c' then str[i]='a'+(('c'-'a')+3)='a'+5=f...*/
        }
    }
    printf("The result is: %s ", str);
    return 0;
}
