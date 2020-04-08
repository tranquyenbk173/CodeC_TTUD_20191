#include<bits/stdc++.h>
#include<queue>
#define MAX 1000001
using namespace std;

int n, m, s, t;
typedef pair<int, int> uu;
vector<uu> a[MAX]; // danh sach ke
priority_queue <uu, vector<uu>, greater<uu> > pq; // hang doi uu tien luu cac bo (khoang cach, dinh)
int d[MAX], pre[MAX];
set<int> nonf; // danh dau cac dinh da fixed xong kc hay chua

void input(){
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i<=m; i++){
        cin >> u >> v >> w;
        a[u].push_back(uu(v, w));
    }
    cin >> s >> t;
}

void showpq(priority_queue <uu, vector<uu>, greater<uu> > gq)
{
    priority_queue <uu, vector<uu>, greater<uu> > g = gq;
    while (!g.empty())
    {
        cout << "\t" << g.top().second;
        g.pop();
    }
    cout << '\n';
}

void solve(){
    //khoi tao
    for(int i = 1; i<=n; i++){
        d[i] = MAX;
        pre[i] = s;
        nonf.insert(i);
    }

    for(int i = 0; i<a[s].size(); i++){
        int v = a[s][i].first;
        d[v] = a[s][i].second;
    }
    for(int i = 1; i<=n; i++){
        if(i != s)
            pq.push(uu(d[i], i));
    }

    //showpq(pq); cout << endl;
//    exit(1);

    d[s] = 0; pre[s] = s;
    nonf.erase(s);

    //xu li
    int x, dx;
    while(!nonf.empty()){
        x = pq.top().second;
        dx = pq.top().first;
        pq.pop(); //cout << "\n lay ra "<< x;
        if(dx != d[x]) continue; // do chi them vao set chu ko cap nhat nen loai bo viec xet cac ptu loi thoi
        nonf.erase(x);
        for(int i = 0; i<a[x].size(); i++){
            int v = a[x][i].first;
            if(d[v] > d[x] + a[x][i].second){
                d[v] = d[x] + a[x][i].second;

                pre[v] = x;
                pq.push(uu(d[v], v));
            }
        }
    }
    //cout << endl;
    if(d[t] < MAX) cout << d[t];
    else cout << -1;
//    int xx = t;
//    while(xx != s){
//            cout << xx << "->";
//            xx = pre[xx];
//    }
//    cout << s;
}

int main(){
    input();
    solve();
}
