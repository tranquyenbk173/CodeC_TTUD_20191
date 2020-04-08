#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<string.h>
#define MAX 55
using namespace std;

void qSort(int a[], int left, int right){
    if(left < right){
        int pivot = a[(left + right)/2];
        int s = left, e = right;
        while(s <= e){
            while(a[s] < pivot) s++;
            while(a[e] > pivot) e--;
            if(s <= e){
                int temp = a[s];
                a[s] = a[e];
                a[e] = temp;
                s++;
                e--;
            }
        }
        qSort(a, left,e);
        qSort(a, s, right);

    }
}

int main() {
    cout << "Thỏ Thối!";
}
