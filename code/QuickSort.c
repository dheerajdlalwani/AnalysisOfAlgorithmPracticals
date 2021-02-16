#include <stdio.h>
#define MAX 100
int data[MAX], n, i, pass = 0;

void printArray(int array[])
{
    for (i = 0; i < n; i++)
    {
        printf("| %d |", array[i]);
    }
    printf("\n");
}

void swap(int array[], int c, int d)
{
    int temp = array[c];
    array[c] = array[d];
    array[d] = temp;
}

int partition(int array[], int l, int m)
{
    int k, j;
    int pivot = array[m];
    k = l - 1;
    for (j = l; j < m; j++)
    {
        if (array[j] < pivot)
        {
            k++;
            swap(array, k, j);
        }
    }
    swap(array, k + 1, m);
    return k + 1;
}

void quickSort(int array[], int l, int r)
{
    int pi;

    if (l < r)
    {
        printf("Pass %d: ", pass++);
        printArray(array);
        printf("\n");
        int pi = partition(array, l, r);
        quickSort(array, l, pi - 1);
        quickSort(array, pi + 1, r);
    }
}

int main()
{
    printf("\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Start entering %d integers: \n", n);
    for (i = 0; i < n; i++)
    {
        printf("data[%d] = ", i);
        scanf("%d", &data[i]);
    }

    printf("\n------- Array before sorting -------\n");
    printArray(data);
    printf("------- x ------- x ------- x -------\n\n");

    quickSort(data, 0, n - 1);

    printf("\n------- Array after sorting -------\n");
    printArray(data);
    printf("------- x ------- x ------- x -------\n\n");

    return 0;
}