#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int low, int high)
{
    int i;
    if (low < high)
    {
        int pivot = a[high];
        i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                swap(&a[i], &a[j]);
            }
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        printf("\n");
    }
    quick_sort(a, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}