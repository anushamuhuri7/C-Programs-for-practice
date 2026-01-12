#include<stdio.h>
#include<string.h>
    int palin(char *str){
    char *ptr1=str;
    char *ptr2=str+(strlen(str)-1);
    while(ptr1<ptr2){
     if(*ptr1!=*ptr2){
        return 0;
    }
    ptr1++;
    ptr2--;
   }
   return 1;
}
int main(){
    printf("Enter a string (max 50 characters) to check if it is a palindrome\n");
    char str1[50];
    scanf("%s", str1);
   if(palin(str1)==1){
    printf("The string is a palindrome.\n");
   }
   else{
    printf("The string is not a palindrome.\n");
   }
return 0;
}