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

void selectionSort(int array[])
{
    int i, j, smallest_index, smallest, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            smallest = array[i];
            if (array[j] < smallest)
            {
                smallest = array[j];
                smallest_index = j;
            }
            if (smallest < array[i])
            {
                temp = array[i];
                array[i] = array[smallest_index];
                array[smallest_index] = temp;
            }
        }
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

    selectionSort(data);

    printf("------- Array after sorting -------\n");
    printArray(data);
    printf("------- x ------- x ------- x -------\n\n");

    return 0;
}