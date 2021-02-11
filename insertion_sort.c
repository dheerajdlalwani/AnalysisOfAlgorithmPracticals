#include <stdio.h>
#define MAX 100
int data[MAX], n, i;

void printArray(int array[])
{
    // int n = 10;
    for (i = 0; i < n; i++)
    {
        printf("| %d |", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[])
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
        printf("Pass %d: ", i);
        printArray(array);
        printf("\n");
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

    insertionSort(data);

    printf("------- Array after sorting -------\n");
    printArray(data);
    printf("------- x ------- x ------- x -------\n\n");

    return 0;
}