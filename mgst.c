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
    while (left <= mid)
        b[bArrIdx++] = a[left++];
    while (right <= high)
        b[bArrIdx++] = a[right++];
    for (k = 0; k < n; k++)
        a[low + k] = b[k];
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
    return 0;
}