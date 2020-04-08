#include<bits/stdc++.h>
#include<stack>
#include<vector>
#define MAX 100001
using namespace std;

int n, m, uu, vv;
vector<int> a[MAX]; // mang chua danh sach ke cua cac dinh
int low[MAX], num[MAX], FREE[MAX];
int countt, C; // C - dem so thanh phan lien thong
stack<int> S;

void input(){
    cin >> n >> m;
    for (int i = 1; i<=m; i++){
        cin >> uu >> vv;
        a[uu].push_back(vv);
    }

}

void visit(int u){
    countt ++;
    low[u] = num[u] = countt;
    S.push(u);
    int sz = a[u].size();
    for(int i = 0; i<sz; i++){ // xet nhung dinh ke voi u
        int v = a[u][i];
        if(FREE[v]==1){
            if(num[v] != 0){// neu v tham truoc u
                low[u] = min(low[u], num[v]);
            }else{
                visit(v);
                low[u] = min(low[u], low[v]);

            }
        }
    }

    if(num[u] == low[u]){ //kiem tra xem u co la chot?
        C++;
        while(true){
            int v = S.top();
            S.pop();
            FREE[v] = 0;
            if(u == v) break;
        }
    }
}

void solve(){
    countt = C = 0;
    for (int i = 1; i<=n; i++){
        num[i] = 0; // danh dau la chua tham && thoi diem tham bang 0
        FREE[i] = 1; // chua xac dinh thanh phan lien thong
    }

    for(int i = 1; i<=n; i++){
        if(FREE[i] == 1) visit(i);
    }
    cout << C;
}

int main(){
    ios::sync_with_stdio(false);
    input();
    solve();
}
