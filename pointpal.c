#include<stdio.h>
#include<string.h>
int main(){
    printf("Enter a string (max 200 characters) to check if it is a palindrome\n");
    char str[200];
    fgets(str,sizeof(str),stdin);
    int len=strlen(str);
    char *ptr1=str[0];
    char *ptr2=str[len-1];
    int count=0;
    while(ptr1!=ptr2){
     if(*ptr1==*ptr2){
        count++;
    }
    ptr1++;
    ptr2--;
   }
   if(count==(len/2)){
    printf("The string is a palindrome.\n");
   }
   else{
    printf("The string is not a palindrome.\n");
   }
return 0;
}