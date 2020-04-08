#include<stdio.h>
#define MAX 1000000

void qSort(int a[], int left, int right)
{
    if (left < right) // Neu day co nhieu hon mot phan tu
    {
        int pivot = a[left], s = left, e = right;
        int temp;

        while (s < e){
            while (a[s] <= pivot) s++;
            while (a[e] > pivot) e--;
            if (s < e){
                temp = a[s];
                a[s] = a[e];
                a[e] = temp;
            }
        }
        temp = a[left];
        a[left] = a[e];
        a[e] = temp;

        qSort(a, left, e-1);
        qSort(a, e+1, right);

    }
}

int main(){
    int n, a[MAX], i;

    scanf("%d", &n);
    for(i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }

    qSort(a, 0, n-1);

    for(i = 0; i<n; i++)
        printf("%d ", a[i]);

}
