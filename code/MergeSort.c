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

void merge(int array[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int array1[n1];
    int array2[n2];
    int p1 = 0;
    int p2 = 0;
    int j = 0;
    int k = l;

    for (j = 0; j < n1; j++)
    {
        array1[j] = array[l + j];
    }

    for (j = 0; j < n2; j++)
    {
        array2[j] = array[mid + 1 + j];
    }

    while (p1 < n1 && p2 < n2)
    {
        if (array1[p1] > array2[p2])
        {
            array[k] = array2[p2];
            p2++;
            k++;
        }
        else
        {
            array[k] = array1[p1];
            p1++;
            k++;
        }
    }

    while (p1 < n1)
    {
        array[k] = array1[p1];
        p1++;
        k++;
    }
    while (p2 < n2)
    {
        array[k] = array2[p2];
        p2++;
        k++;
    }
}

void mergeSort(int array[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        mergeSort(array, l, mid);
        mergeSort(array, mid + 1, r);
        merge(array, l, mid, r);
        printf("Pass No. %d: ", pass);
        printArray(array);
        pass++;
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

    mergeSort(data, 0, n - 1);

    printf("\n------- Array after sorting -------\n");
    printArray(data);
    printf("------- x ------- x ------- x -------\n\n");

    return 0;
}
