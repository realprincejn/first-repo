//  Count Sort

#include <stdio.h>

int count_sort(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    int countarr[max + 1];
    for (int i = 0; i < (max + 1); i++)
        countarr[i] = 0;

    for (int i = 0; i < n; i++)
        countarr[arr[i]]++;

    for (int i = 1; i < (max + 1); i++)
        countarr[i] = countarr[i - 1] + countarr[i];

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[countarr[arr[i]] - 1] = arr[i];
        countarr[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n;
    printf("Enter length of input array\n");
    scanf("%d", &n);

    int input[n];
    printf("Enter input array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);

    printf("The sorted array is \n");
    count_sort(input, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", input[i]);
    }
    printf("end");
}