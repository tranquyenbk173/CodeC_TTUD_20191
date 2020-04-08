#include<bits/stdc++.h>
#define M 10001
using namespace std;
int n, m;
int x[M], y[M];
int f[M][M]; // sol table

void input(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++) cin >> x[i];
    for(int i = 1; i<=m; i++) cin >> y[i];
}

void solve(){
    int i, j, maxx;
    // khoi tao co so:
    for(i = 0; i<=n; i++){
        f[i][0] = 0;
    }
    for(i = 1; i<=m; i++){
        f[0][i] = 0;
    }

    //lap:
    for(i = 1; i<=n; i++){
        for(j = 1; j<=m; j++){
            if(x[i] == y[j]) f[i][j] = 1 + f[i-1][j-1];
            else{
                maxx = f[i-1][j];
                if(f[i][j-1] > maxx) maxx = f[i][j-1];
                f[i][j] = maxx;
            }
        }
    }

    cout << f[n][m];
}

int main(){
    input();
    solve();
}
