#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;

int n, gap;
float a[MAX];

void input(){
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
}

void SWAP(float &a, float &b){
    float temp = a;
    a = b;
    b = temp;
}

void getNextGap(){
    gap = (gap * 10)/13;
    if (gap < 1) gap = 1;
}

void combSort(float a[], int n){
    gap = n;
    int swapping;
    do{
        swapping = 0;
        getNextGap();
        for (int i = 0; i<n-gap; i++){
            if (a[i] > a[i+gap]){
                SWAP(a[i], a[i+gap]);
                swapping = 1;
            }
        }
    } while (swapping == 1 || gap != 1);

}

void solve(){
    combSort(a, n);

    for (int i = 0; i<n; i++)
        printf("%.2f ", a[i]);
}

int main(){
    input();
    solve();
}
