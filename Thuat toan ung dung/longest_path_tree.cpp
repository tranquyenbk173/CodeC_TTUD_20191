/*
    thuat toan:
    - DFS(s) tim dinh u sao cho do dai tu s den n la max
    - DFS(u) tim dinh v sao cho do dai tu u den v la max
    do chinh la duong di dai nhat tren cay
*/

#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, m;
typedef pair<int, int> uu;
vector<uu> a[MAX]; // danh sach ke
int s, maxS, d, maxd;
int visited[MAX];
int x[MAX];
int y[MAX];

void printG(){
    for(int i = 1; i<=n; i++){
        cout << endl << "a[" << i << "] = ";
        for(int j = 0; j<a[i].size(); j++){
            cout << "("<< a[i][j].first << " "<< a[i][j].second << ")" << ", ";
        }
    }
}

void input(){
    cin >> n;
    int u, v, w;
    for(int i = 1; i<n; i++){
        cin >> u >> v >> w;
        a[u].push_back(uu(v, w));
        a[v].push_back(uu(u, w));
    }
    //printG();
}

void solution(){
    {
        maxS = s;
        maxd = d; //cout << "\n maxd = " << maxd;
        for(int i = 1; i<=maxd; i++)
            y[i] = x[i];
    }
}

void TRY(int k){
    int u = x[k-1]; //cout << "\n u = " << u;
    for(int i = 0; i<a[u].size(); i++){
        int v = a[u][i].first;
        //cout << "\n v = "<< v;
        if(visited[v] == 0){
            visited[v] = 1;
            d++;
            x[k] = v; //cout << "\n chon " << v ;
            s += a[u][i].second;

            if(s > maxS) solution();
            TRY(k+1);

            visited[v] = 0;
            s -= a[u][i].second;
            d--;
        }
    }
}

void solve(){
    for(int i = 1; i<=n; i++) visited[i] = 0;
    s = maxS  = 0; d = 1;
    x[1] = 1; visited[1] = 1;
    TRY(2);
    int u = y[maxd];

    //cout << "\n _______________";
    for(int i = 1; i<=n; i++) visited[i] = 0;
    maxd = d = 1; s = maxS = 0;
    x[1] = u; visited[u] = 1;
    TRY(2);
//    cout << endl;
//
//    for(int i = 1; i<=maxd; i++){
//        cout << y[i] << " ";
//    }

    cout<< maxS;
}

int main(){
    input();
    solve();
}
