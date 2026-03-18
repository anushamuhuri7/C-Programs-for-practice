#include <stdio.h>
#include <stdlib.h>
void bead_sort(int *a, int n)
{
    int i, j, max = 0, sum;
    unsigned char *beads;
    for (i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    beads = (unsigned char *)calloc(max * n, sizeof(unsigned char));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < a[i]; j++)
            beads[j * n + i] = 1;
    }
    for (j = 0; j < max; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum += beads[j * n + i];
        for (i = 0; i < sum; i++)
            a[i] = a[i] + 1;
    }
}