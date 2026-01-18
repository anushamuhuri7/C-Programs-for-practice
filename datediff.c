#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date{
 int day;
 int month;
 int year;
};
int main(){
    struct date d1;
    struct date d2;
    printf("Enter first date (dd/mm/yyyy) (with spaces in between): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
    printf("Enter second date (dd/mm/yyyy) (with spaces in between): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);
    int diff= (d1.day-d2.day);

}