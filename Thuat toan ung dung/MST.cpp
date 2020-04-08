
#include<bits/stdc++.h>
#include<queue>
#define MAX 100001
using namespace std;

typedef pair<int, int> edge;
typedef pair<int, edge> w_e;
priority_queue<w_e, vector<w_e>, greater<w_e> > pq;
int n, m;
int ww, minW; // trong so cua cay khung
set<int> VT; // chua cac dinh da duoc them vao cay khung

void printG(priority_queue<w_e, vector<w_e>, greater<w_e> > pq){
    priority_queue<w_e, vector<w_e>, greater<w_e> > q = pq;
    while(!pq.empty()){
        w_e x = pq.top();
        pq.pop();
        cout << "(" << x.second.first << ", " << x.second.second << ", "<< x.first<< "), ";
    }
    cout << endl;
}

void input(){
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i<=m; i++){
        cin >> u >> v >> w;
        edge e = make_pair(u, v);
        pq.push(w_e(w, e));
    }
    //printG(pq);
}

void solve(){
    ww = 0;
    w_e x = pq.top(); pq.pop();
    VT.insert(x.second.first);
    VT.insert(x.second.second);
    ww += x.first;
    cout << "\n lay ra: (" << x.second.first << ", "<< x.second.second << ")";
    while(VT.size() < n){
        w_e x = pq.top(); pq.pop();
        if()
        VT.insert(x.second.first);
        VT.insert(x.second.second);
        ww += x.first;
        cout << "\n lay ra: (" << x.second.first << ", "<< x.second.second << ")";
    }
    cout << ww;
}

int main(){
    input();
    solve();
}
