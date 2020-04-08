#include<bits/stdc++.h>
#define N_MAX 50
#define M_MAX 50

using namespace std;

int n, m;
int a[N_MAX][N_MAX];
int f[M_MAX];
int h[N_MAX];
int sz[N_MAX];
int t[N_MAX][M_MAX];
int f_best;
int x[N_MAX];

void input(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> h[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> sz[i];
        for(int j = 1; j<sz[i]; j++)
            cin >> t[i][j];
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> a[i][j];
        }
    }
}

int check(int v, int k){
    for(int i = 1; i<=k-1; i++){
        if(a[i][k] && v == x[i]) return 0;
    }
    return 1;
}

void solution(){
    int Max =  0;
    for(int i = 1; i<=m; i++)
        if (Max < f[i]) Max = f[i];
    if (Max < f_best) f_best = Max;
}

void TRY(int k){
    for(int i = 1; i<=sz[k]; i++){
        int v = t[k][i];
        if(check(v, k)){
            x[k] = v;
            f[v] += h[k];
            if(k == n){
                solution();
            }else TRY(k+1);
            f[v]-=h[k];
        }
    }
}

void solve(){
    f_best = 100000;
    for(int i = 1; i<=m; i++){
        f[i] = 0;
    }
    TRY(1);
    if(f_best == 10000) cout << -1;
    else cout << f_best;
}
int main(){
    input();
    solve();
}
