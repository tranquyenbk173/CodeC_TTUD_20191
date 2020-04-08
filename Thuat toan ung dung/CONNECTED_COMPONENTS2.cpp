#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, m;
vector<int>u[MAX];
int visited[MAX];
int num;

void input(){
    cin >> n >> m;

    int x, y;
    for(int i = 1; i<=m; i++){
        cin >> x >> y;
        u[x].push_back(y);
        u[y].push_back(x);
    }
}

void dfs(int v){
    visited[v] = 1;
    for(int i = 0; i < u[v].size(); i++){
        int t = u[v][i];
        if(visited[t] == 0){
            dfs(t);
        }
    }
}

void solve(){
    num = 0;
    for(int i = 1; i<=n; i++){
        visited[i] = 0;
    }

    for(int i = 1; i<=n; i++){
        if(visited[i] == 0){
            num++;
            dfs(i);
        }
    }

    cout << num;
}

int main(){
    input();
    solve();
}
