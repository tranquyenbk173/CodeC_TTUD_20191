#include<bits/stdc++.h>
#define M 1000

using namespace std;

int n, i, j;
int x[M], xx[M];

int main(){
    cout << "Nhap n: ";
    cin >> n;

    for(i = 1; i<=n; i++){
        x[i] = 0;
        xx[i] = n-i+1;
    }

    while(i > 0){
        for(j = 1; j<=n; j++){
            if(x[j] == 1) cout << xx[j] << " ";
        }
        cout << endl;

        j = n;
        while(x[j]==1 && j>0) j--;
        i = j;
        x[j] = 1;
        for(j = i+1; j<=n; j++) x[j] = 0;
    }
}
