#include<bits/stdc++.h>
#define M 1000
using namespace std;

int i, j, n;
int x[M];

void solution(){
    for(int i = 1; i<=n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void TRY(int k){
    for(int i = 0; i<=1; i++){
        x[k] = i;
        if(k == n) solution();
        else TRY(k+1);
    }

}

int main(){
    cout<< "Nhap n: ";
    cin >> n;

    x[0] = 0;
    TRY(1);
}
