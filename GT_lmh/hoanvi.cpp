#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

int n, i, j, t, x[MAX];

void SWAP(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    cout << "Nhap n: ";
    cin >> n;

    if(n== 0) {
        cout << "Day rong!";
        return 0;
    }

    for(i = 1; i<=n; i++) x[i] = i;

    while(i >= 1){
        for(j = 1; j<=n; j++) cout << x[j] << " ";
        cout <<endl;

        j = n-1;
        while(x[j] >= x[j+1] && j >=1) j--;
        i = j;

        j = n;
        while(x[j]<=x[i]) j--;
        SWAP(x[i], x[j]);
        j = i+1; t = n;
        while(j<t){
            SWAP(x[j], x[t]);
            j++; t--;
        }
    }
}
