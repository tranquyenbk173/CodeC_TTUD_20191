#include<bits/stdc++.h>

#define MAX 100001
using namespace std;
int n, m;
vector<int> a[MAX];
int visited[MAX];
int x[MAX];

void input(){
    cin >> n >>m;
    int u, v;
    for(int i = 1; i<=m; i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void printG(){
    for(int i = 1;  i<=n; i++){
        cout << endl << "a["<< i << "] = ";
        for(int j = 0; j<a[i].size(); j++){
            cout << a[i][j] << " ";
        }
     }
}

void solution(){
    cout << endl;
    for(int i = 1; i<=n; i++){
        cout << x[i] << " ";
    }
    cout << x[1];
}

int check(int u, int v){ // kiem tra u co ke voi v?
    for(int i = 0; i<a[v].size(); i++){
        if(a[v][i] == u) return 1;
    }
    return 0;
}

void TRY(int k){
    int u = x[k-1];
    for(int j = 0; j<a[u].size(); j++){
        int v = a[u][j];
        if(visited[v]  == 0){
            x[k] = v;
            visited[v] = 1;
            if(k == n){
                if(check(v, 1)) solution();
            }else TRY(k+1);

            visited[v] = 0;
        }
    }
}

void solve(){
    for(int i = 1; i<=n; i++) visited[i] = 0;
    x[1] = 1; visited[1] = 1;
    TRY(2);
}

int main(){
    input();//printG();
    solve();
}
