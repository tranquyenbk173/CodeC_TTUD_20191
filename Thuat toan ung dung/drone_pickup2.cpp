#include<bits/stdc++.h>
#define M 3001
using namespace std;
int n, k;
int c[M], a[M];
int f[M][M]; // f[i][t] - luong hag lay duoc khi toi i sau t buoc.

void input(){
    int i;
    cin >> n >> k;
    for(i = 1; i<=n; i++) cin >> c[i];
    for(i = 1; i<=n; i++) cin >> a[i];
}

void solve(){
    f[1][0] = c[1];

    for(int i = 2; i<=n; i++){
        for(int t = 1; t<i; t++){
            f[i][t] = 0;
        }
    }

    for(int i = 2; i<=n; i++){
        for(int t = 1; t<i && t<=k; t++){
            for(int j = 1; j<i; j++){
                if(a[j] + j >= i && f[j][t-1] > 0 && f[i][t] < f[j][t-1] + c[i])
                    f[i][t] = f[j][t-1] + c[i];
            }
        }
    }
    int maxx = 0;
    for(int t = 1; t<=k; t++)
        if(f[n][t] > maxx) maxx = f[n][t];

    if(maxx > 0) cout << maxx;
    else cout << -1;
}

int main(){
    input();
    solve();
}
