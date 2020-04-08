#include<bits/stdc++.h>
#define M 1000

using namespace std;

int m, n, io, jo; // dau vao, m - so hang, n - so cot
int a[M][M];
int dx[M*M], dy[M*M]; // Ghi nhan loi giai bo phan
int cost, mincost;

void input(){
    cin >> m >> n >> io >> jo;
    int i, j;
    for (i = 0; i<m; i++)
        for (j = 0; j<n; j++)
            cin >> a[i][j];

    io--;
    jo--;
}

int isEscaped(int x, int y){
    if (x == 0 || x == m-1) return 1;
    if (y == 0 || y == n-1) return 1;
    return 0;
}

void solution(){
    if (mincost > cost)
        mincost = cost;
}

void TRY(int k){
    int x = dx[k-1];
    int y = dy[k-1];
    int i, j;
    for (i = x-1, j= y; i<=x+1; i++)
            if (a[i][j] == 0){
                dx[k] = i;
                dy[k] = j;
                a[i][j] = 1;
                cost += 1;
                if (isEscaped(i, j)) solution();
                else TRY(k+1);
                cost --;
                a[i][j] = 0;
            }
    for (j = y-1, i = x; j<=y+1; j++)
            if (a[i][j] == 0){
                dx[k] = i;
                dy[k] = j;
                a[i][j] = 1;
                cost += 1;
                if (isEscaped(i, j)) solution();
                else TRY(k+1);
                cost --;
                a[i][j] = 0;
            }
}

void solve(){
    dx[0] = io;
    dy[0] = jo;
    a[io][jo] = 1;
    mincost = 10000;
    cost = 0;

    TRY(1);
}

int main(){
    input();
    solve();
    if (mincost < 10000) cout << mincost+1;
    else cout << -1;
}
