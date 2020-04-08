#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int n, m;
int u[MAX], v[MAX];
int adj[2*MAX], head[MAX]; // adj chua danh sach cac dinh ke
                        // head[i] la chi so phan tu cuoi cua dske dinh i
int num; // so tp lien thong
int visited[MAX];

void input(){
    cin >> n >> m;

    for(int i = 1; i<=m; i++){
        cin >> u[i] >> v[i];
    }

    int h = 1;
    for(int i = 1; i<=n; i++){ // tim ds ke cho i
        for(int j = 1; j<=m; j++){ // xet (u, v)
            if(u[j] == i){
                adj[h] = v[j];
                head[i] = h++;
            }else if(v[j] == i){
                adj[h] = u[j];
                head[i] = h++;
            }
        }
    }
}

void DFS(int u){
    visited[u] = 1;
    for(int v = head[u-1] + 1; v<=head[u]; v++){
        int t = adj[v];
        if(visited[t] == 0){
            DFS(t);
        }
    }
}

void solve(){

    num = 0; head[0] = 0;
    for(int i = 1; i<=n; i++) visited[i] = 0;

    for(int i = 1; i<=n; i++){
        if(visited[i] == 0){
            num++;
            DFS(i);
        }
    }

    cout << num;
}

int main(){
    input();
    solve();
}
