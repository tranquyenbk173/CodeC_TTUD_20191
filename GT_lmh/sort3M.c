#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

void qSort(float a[], int left, int right)
{
    if (left < right) // Neu day co nhieu hon mot phan tu
    {
        float pivot = a[left];
        int s = left, e = right;
        float temp;

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

float main(){
    float a[MAX];
    int i, n;

    cin >> n;
    for(i = 0; i<n; i++){
        cin >> a[i];
    }

    qSort(a, 0, n-1);

    for(i = 0; i<n; i++)
        printf("%.2f ", a[i]);

}
