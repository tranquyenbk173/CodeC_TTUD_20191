#include<bits/stdc++.h>
#define M 1000

using namespace std;
int n;
int x[M], xx[M];

void solution(){
    for(int i = 1; i<=n; i++){
        cout << xx[i] << " ";
    }
    cout << endl;
}

void TRY(int k){
    for(int i = 1; i<=n; i++){
        if(x[i] == 0 && i != k){
            xx[k] = i;
            x[i] = 1;

            if(k == n) solution();
            else TRY(k+1);

            x[i] = 0;
        }
    }
}

int main(){
    cout << "Nhap n: ";
    cin >> n;

    for(int i = 1; i<=n; i++) x[i] = 0;
    TRY(1);
}
