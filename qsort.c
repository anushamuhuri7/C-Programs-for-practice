#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1;
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
void quick_sort()