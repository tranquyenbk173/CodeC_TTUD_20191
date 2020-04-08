#include<bits/stdc++.h>
#define M 1000
using namespace std;

int n, i, j, x[M];

int main(){
     cout << "Nhap n: ";
     cin >> n;

     for(int k = 1; k<=n; k++){//  liet ke cac tap con k phan tu:
        for(i = 1; i<=k; i++) x[i] = i;
        while(i>0){
            for(j = 1; j<=k; j++) cout << x[j] << " ";
            cout <<endl;

            j = k;
            while(x[j] >= n-k+j && j>0) j--;
            i = j;
            x[j] ++;
            for(j = i+1; j<=k; j++) x[j] = x[j-1] + 1;
        }
     }
}
