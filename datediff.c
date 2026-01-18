#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct date{
 int day;
 int month;
 int year;
}Date;
const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int countLeap(Date d){
    int years=d.year;
    if (d.month <= 2) {
        years--;
    }
    return (years / 4) - (years / 100) + (years / 400);
}
long int getDays(Date d) {
    // 1. Calculate days from years
    long int n = (long int)d.year * 365 + d.day;

    // 2. Add days for months in the current year
    for (int i = 0; i < d.month - 1; i++) {
        n += monthDays[i];
    }

    // 3. Add an extra day for every leap year
    n += countLeap(d);

    return n;
}
int getDiff(Date d1, Date d2) {
    long int n1 = getDays(d1);
    long int n2 = getDays(d2);

    // Return the absolute difference
    return (n2 > n1) ? (n2 - n1) : (n1 - n2);
}
int main(){
    Date d1, d2;
    printf("Enter first date (dd mm yyyy) (with spaces in between): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
    printf("Enter second date (dd mm yyyy) (with spaces in between): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);
    int diff = getDiff(d1, d2);
    printf("\nDate 1: %02d/%02d/%d", d1.day, d1.month, d1.year);
    printf("\nDate 2: %02d/%02d/%d", d2.day, d2.month, d2.year);
    printf("\nDiff: %d days\n", diff);
    return 0;
}