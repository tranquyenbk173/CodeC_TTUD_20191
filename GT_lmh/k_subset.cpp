#include<bits/stdc++.h>
#define MAX 1000

using namespace std;
int n, k, i, x[MAX], j;


int main(){
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;
    if(k == 0){
        cout << "Day rong!";
        return 0;
    }
    for(i = 0; i<k; i++) x[i] = i;
    i = k-1;
    while(i>=0){
        for(j = 0; j<k; j++) cout << x[j] << " ";
        cout <<endl;
        j = k-1;
        while(x[j]>=n-k+j && j >=0) j--;
        i = j;
        if(j >= 0) x[j] = x[j] + 1;
        for(int j = i+1; j<k; j++) x[j] = x[j-1] + 1;
    }
}
