#include <stdio.h>
#include <stdlib.h>

void insertion_sort(double *arr, int size);

int main(int argc, char *argv[])
{
    double arr[] = {2.3, -1.2, 3.4, -34.2};
    insertion_sort(arr, 4);
    for (int i = 0; i < 4; ++i)
    {
        printf("%lf ", arr[i]);
    }
    return 0;
}

void insertion_sort(double *arr, int size)
{
    for (int ind = 1; ind < size; ++ind)
    {
        double key = arr[ind];
        int i = ind - 1;
        while (i > -1 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}