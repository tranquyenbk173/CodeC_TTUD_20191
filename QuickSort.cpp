
#include<stdio.h>

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b  = temp;
}

void Partition(int a[], int left, int right, int &i_pivot)
{
    int pivot = a[i_pivot];
    Swap(a[right], a[pivot]);

    i_pivot = left;
    for(int i = left; i<right; i++)
    {
        if (a[i]<=pivot)
        {
            Swap(a[i], a[i_pivot]);
            i_pivot++;
        }
    }

    Swap(a[right], a[i_pivot]);
}

void QuickSort(int a[], int left, int right)
{
    int i_pivot = (left + right)/2;
    Partition(a, left, right, i_pivot);
    QuickSort(a, left, i_pivot-1);
    QuickSort(a, i_pivot+1, right);
}

