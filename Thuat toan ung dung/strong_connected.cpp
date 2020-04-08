#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n, m, num;
vector<int> a[MAX]; // ds ke cua G
vector<int> aT[MAX]; // ds ke cua GT
int q[MAX]; // luu danh sach cac dinh theo thu tu ket thuc tham
int visited[MAX]; // danh dau dinh da tham
int f;


void input(){
    cin >> n >> m;

    int u, v;
    for(int i = 1; i<=m; i++){
        cin >> u >> v;
        a[u].push_back(v);
        aT[v].push_back(u);
    }
}

void dfs(int u){
    int t;
    visited[u] = 1;
    int sz = a[u].size();
    for(int i = 0; i<sz; i++){
        t = a[u][i];
        if(visited[t] == 0){
            dfs(t);
        }
    }
    q[f++] = u;
}

void dfs2(int u){
    int t;
    visited[u] = 1;
    int sz = aT[u].size();
    for(int i = 0; i<sz; i++){
        t = aT[u][i];
        if(visited[t] == 0){
            dfs2(t);
        }
    }
}

void solve(){
    f = 0;
    for(int i = 1; i<=n; i++){
        visited[i] = 0;
    }

    for(int i = 1; i<=n; i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }

    for(int i = 1; i<=n; i++){
        visited[i] = 0;
    }

    int t;
    num = 0;
    for(int i = f-1; i >=0; i--){
        t = q[i];
        if(visited[t] == 0){
            num++;
            dfs2(t);
        }
    }

    cout <<num;
}

int main(){
    ios::sync_with_stdio(false);
    input();
    solve();
}


