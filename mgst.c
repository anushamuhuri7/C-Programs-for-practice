#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int low, int mid, int high)
{
    int n = high - low + 1, left = low, right = mid + 1, bArrIdx = 0, k;
    int *b = malloc(n * sizeof(int));
    while (left <= mid && right <= high)
    {
        if (a[left] < a[right])
            b[bArrIdx++] = a[left++];
        else
            b[bArrIdx++] = a[right++];
    }
    printf("The sorted array is: ");
    for (k = 0; k < n; k++)
        printf("%d ", b[k]);
    printf("\n");
    free(b);
}
void msort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        msort(a, low, mid);
        msort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(a) / sizeof(a[0]);
    printf("The original array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    msort(a, 0, n - 1);
    return 0;
}