#include<bits/stdc++.h>
#define M 100001
using namespace std;
int n;
int x[M];
int L[M]; // L[i] - do dai day con tang dai nhat ket thuc tai i

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> x[i];
}

void solve(){
    int maxx = 1;
    for(int i = 1; i<=n; i++){
            L[i] = 1;
        for(int j = 1; j<i; j++){
            if(x[j] < x[i] && L[i] < L[j] + 1) L[i] = L[j] + 1;
        }
        if(maxx < L[i]) maxx = L[i];
    }

    cout << maxx;
}

int main(){
    input();
    solve();
}
