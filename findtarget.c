#include <stdio.h>
int findAr(int size, int ar[], int target);
int main()
{
    int ar[20];
    int size, i, target;
    
    printf("Enter array size: ");
    scanf("%d", &size);
    printf("Enter %d data: ", size);
    for (i=0; i<=size-1; i++)
        scanf("%d", &ar[i]);
    printf("Enter the target number: ");
    scanf("%d", &target);
    printf("findAr(): %d",
        findAr(size, ar, target));
    return 0;
}
int findAr(int size, int ar[], int target)
{
    int count=-1;
   for(int i=0;i<size;i++){
    if(ar[i]==target){
        count++;
        return i;
    }
   }
   if(count==-1){
   return count;
   }
}