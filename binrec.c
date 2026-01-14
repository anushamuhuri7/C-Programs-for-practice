#include<stdio.h>
#include<stdlib.h>
int binsrch(int arr[], int x, int low, int high){
    int mid=(low+high)/2;
    if(x==arr[mid])
    return mid;
    else{
        if(x>arr[mid])
        return binsrch(arr, x, mid+1, high);
        else
        return binsrch(arr, x, low, mid-1);
    }
}
int main(){
    int size;
    int *arr;
    printf("Enter the size of an array: ");
    scanf("%d", &size);
    arr=(int*)malloc(size*sizeof(int));
    printf("\n Enter elements of the array (sorted): \n");
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    int position = binsrch(arr, x, 0, size - 1);
    printf("Position of element: %d\n", position);
    free(arr);
    return 0;
} /*code is now corrected*/
