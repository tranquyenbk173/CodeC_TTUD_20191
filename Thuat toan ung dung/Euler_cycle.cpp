#include<bits/stdc++.h>
#include<set>
#define MAX 100001
using namespace std;

int n; //num of nodes
int m; // num of edges
set<int> a[MAX]; // a[x] = the set of adj node to x

void input(){
    int u, v;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
    }

}

void printG(){
    for(int v = 1; v<=n; v++){
        cout << endl;
        cout << "a["<< v<< "] = ";
        for(set<int>::iterator it  = a[v].begin(); it!=a[v].end(); it++){
            int x = *it;
            cout << x << " ";
        }
    }
}

void solve(){
    stack<int> S, CE;
    S.push(1);
    while(!S.empty()){
        int x = S.top();
        if(!a[x].empty()){
            int y = *(a[x].begin());
            S.push(y);
            a[x].erase(y);
            a[y].erase(x);
        }else{
            S.pop();
            CE.push(x);
        }
    }

    while(!CE.empty()){
        int x = CE.top();
        CE.pop();
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    input();
    //printG();
    solve();
}
