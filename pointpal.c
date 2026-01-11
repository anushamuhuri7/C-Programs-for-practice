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
    printf("Enter a string (max 200 characters) to check if it is a palindrome\n");
    char str1[200];
    fgets(str1,sizeof(str1),stdin);
   if(palin(str1)){
    printf("The string is a palindrome.\n");
   }
   else{
    printf("The string is not a palindrome.\n");
   }
return 0;
}