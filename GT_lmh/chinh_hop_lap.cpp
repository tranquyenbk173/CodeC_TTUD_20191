#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

int k, i, j, n, x[MAX];

int main(){
    cout << "Nhap n, k: ";
    cin >>  n >> k;

    for(i = 0; i<k; i++){
        x[i] = 0;
    }

    while(i>=0){
        for(j = 0; j<k; j++) cout << x[j] << " ";
        cout << endl;

        j = k-1;
        while(x[j] >= n-1 && j>=0) j--;
        i = j;

        x[j] ++;
        for(j = i+1; j<k; j++) x[j] =  0;
    }
}
