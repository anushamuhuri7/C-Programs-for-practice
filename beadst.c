#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bead_sort(int *a, int n)
{
    int i, j, max = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    unsigned char *beads = (unsigned char *)calloc(max * n, sizeof(unsigned char));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < a[i]; j++)
        {
            beads[i * max + j] = 1;
        }
    }
    for (j = 0; j < max; j++)
    {
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }

        for (i = n - sum; i < n; i++)
        {
            beads[i * max + j] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        int row_sum = 0;
        for (j = 0; j < max; j++)
        {
            row_sum += beads[i * max + j];
        }
        a[i] = row_sum;
    }

    free(beads);
}

int main()
{
    int a[] = {5, 3, 1, 7, 4};
    int n = sizeof(a) / sizeof(a[0]);

    bead_sort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}