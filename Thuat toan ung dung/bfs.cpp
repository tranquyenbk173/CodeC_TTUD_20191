#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, m;
vector<int> a[MAX];
char color[MAX];
int t;
int d[MAX], f[MAX], p[MAX];

void input(){
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
}

void printGraph(){
    for(int i = 1; i<=n; i++){
        cout << "a[" << i << "] = ";

        for(int j = 0; j<a[i].size(); j++){
            cout<< a[i][j] <<" ";
        }
        cout<<endl;
    }
}

void dfs(int u){
    t++;
    d[u] = t;
    color[u] = 'G';
    for(int v = 0; v < a[u].size(); v++){
        int t = a[u][v];
        if(color[t] == 'W'){
            p[t] = u;
            dfs(t);
        }
    }
    color[u] = 'B';
    t ++;
    f[u] = t;
}

void DFS(){

    for(int i = 1; i<=n; i++){
        color[i]  = 'W';
    }
    t = 0;
    for(int i = 1; i<=n; i++){
        if(color[i] == 'W'){
            dfs(i);
        }
    }

}

void duongdi(int bd, int kt){
    int t = p[kt];
    if(t == bd) return;
    duongdi(bd, t);
    cout << t << " -";
}

int main(){
    input();

    DFS();

    cout << "Duong di tu 1 den 4:";
    cout << 1 << " - ";
    duongdi(1, 4);
    cout << " 4";

}
