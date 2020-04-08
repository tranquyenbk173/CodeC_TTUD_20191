#include<bits/stdc++.h>
#define M 1000

using namespace std;

int n, kk;
int x[M];

void solution(){
    for(int i = 1; i<=kk; i++){
        cout << x[i] << " ";
    }
    cout<< endl;
}

void TRY(int k){
    for(int i = 1; i<=n; i++){
        x[k] = i;

        if(k == kk) solution();
        else TRY(k+1);
    }
}

int main(){
    cout << "Nhap n, k: ";
    cin >> n >> kk;

    TRY(1);
}
