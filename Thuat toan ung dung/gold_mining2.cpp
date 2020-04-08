#include<bits/stdc++.h>
#define M 100001
using namespace std;
int n, L1, L2;
int a[M];
int f[M]; // f[i] = luong hang lay duoc nhieu nhat khi toi diem i.

void input(){
    cin >> n >> L1 >> L2;
    for(int i = 1; i<=n; i++) cin >> a[i];
}

void solve(){
    int i, j, maxx = a[1];

    for(i = 1; i<=L1; i++) f[i] = a[i];
    for(i = L1+1; i<=n; i++){
        for(j = L1; j<=L2; j++){
            if(j < i && f[i] < f[i-j] + a[i])
                f[i] = f[i-j] + a[i];
        }
        if(maxx < f[i]) maxx = f[i];
    }

    cout << maxx;
}

int main(){
    input();
    solve();
}
