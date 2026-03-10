#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int low, int mid, int high)
{
    int n = high - low + 1, left = low, right = mid + 1, bArrIdx = 0, k;
    int b = malloc(n * sizeof(int));
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