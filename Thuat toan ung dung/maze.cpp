#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

int m, n, io, jo, x, y, mincost;
int a[MAX][MAX]; // Dung lam ma tran chi phi luon
int qx[MAX*MAX], qy[MAX*MAX], head, tail;

// For Queue:
void push(int xx, int yy){

    qx[++head] = xx;
    qy[head] = yy;
    a[xx][yy] = a[x][y] + 1;
}

void pop(){
    x = qx[tail];
    y = qy[tail++];
}

//end Queue

void input(){
    cin >> m >> n >> io >> jo;
    for (int i = 1; i<=m; i++)
        for (int j = 1; j<=n; j++)
            cin >> a[i][j];
}

int init(){
    head = tail = 0;
    qx[head] = io;
    qy[head] = jo;
    a[io][jo] = 01;

    mincost = 10000;
}

void solution(){
    if (a[x][y] < mincost)
        mincost = a[x][y];
}

void solve(){

    while (head >= tail){
        pop();
        if (x == 1 || x == m || y == 1 || y == n) solution();
        else{
            if (a[x+1][y] == 0) push(x+1, y);
            if (a[x-1][y] == 0) push(x-1, y);
            if (a[x][y+1] == 0) push(x, y+1);
            if (a[x][y-1] == 0) push(x, y-1);
        }
    }

}

int main(){
    input();
    init();
    solve();
    if (mincost < 10000) cout << mincost;
    else cout << -1;
}
