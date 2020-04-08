#include<bits/stdc++.h>
#include<vector>
#define MAX_L 55
#define MAX_M 25
using namespace std;

int N, M, s, L;
int u[MAX_M], v[MAX_M], c[MAX_M], l[MAX_M];
int lk[MAX_M][MAX_M];
int x[MAX_M], y[MAX_M];
int choosed[MAX_M];
int C, minC;
int ll[MAX_M]; // ll[i]: do tre tai nut i
vector<int> a[25];
int r[MAX_M];
int visited[MAX_M];

void input(){
    cin >> N >> M >> s >> L;
    int uu, vv, cc, ll;
    for(int i =1; i<=M; i++){
        cin >> u[i] >> v[i] >> c[i] >> ll; // cac thong so cua canh thu i
        lk[u[i]][v[i]] = lk[v[i]][u[i]] = ll;
    }
}

void SWAP(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void qSort(int left, int right)
{
    if (left < right) // Neu day co nhieu hon mot phan tu
    {
        int pivot = c[(left + right)/2];
        int s = left, e = right;
        int temp;

        while (s <= e){
            while (c[s] < pivot) s++;
            while (c[e] > pivot) e--;
            if (s <= e){
                SWAP(c[s], c[e]);
                SWAP(u[s], u[e]);
                SWAP(v[s], v[e]);
                SWAP(l[s], l[e]);
                s++; e--;
            }
        }

        qSort(left, e);
        qSort(s, right);
    }
}


int root(int u){ // disjoin set
    if(r[u] < 0) return u;
    int res = root(r[u]);
    r[u] = res;
    return res;
}

int MERGE(int ru, int rv){
    int delta = abs(r[ru] - r[rv]);
    if(r[ru] < r[rv]){// neu so con cua u nhieu hon v
        r[ru] += r[rv];
        r[rv] = ru;
    }
    else{
        r[rv] += r[ru];
        r[ru] = rv;
    }
    return delta;
}

void tre(int s){
    int sz = a[s].size();
    for(int i = 0; i<sz; i++){ // xet cac dinh ke voi s
        int v = a[s][i];
        if(visited[v] == 0){
            ll[v] = ll[s] + lk[s][v];
            visited[v] = 1;
            tre(v);
        }
    }
}

int check(){ // kiem tra do tre:
    ll[s] = 0;
    for(int i = 1; i<=N; i++){
        visited[i] = 0;
    }
    tre(s);
    //cout << "\n dat tre xong!";
    for(int i = 1; i<=N; i++){
        if(ll[i] > L) return 0;
    }

    return 1;
}

void TRY(int t){
    for(int i = 1; i <= M; i++){
        if(choosed[i] == 0){
            int uu = u[i];
            int vv = v[i];
            int a_ = root(uu), aa = r[a_];
            int b = root(vv), bb = r[b];
            //cout << "\n here!";
            if(a_ != b){
                //cout <<"\n here2";
                C += c[i];
                if (C>minC) goto kkk;
                x[t] = i;
                choosed[i] = 1;
                int delta = MERGE(a_, b);
                a[uu].push_back(vv);
                a[vv].push_back(uu);
            //cout << "\n safe!";

                if(t == N-1){// khi da chon duoc du n-1 canh cho cay khung:
                        //cout << "\n n-1";
                    if(check()){
                        //cout << "\n check!";
                        //cout << C<<endl;
                        if(minC > C) minC = C;
                        cout << minC;
                        exit(1);
                        //exit(1);
                    }else{
                        for(int ii = 1; ii<=N; ii++) a[ii].clear();
                    }
                }else TRY(t+1);


                r[a_] = aa;
                r[b] = bb;
                choosed[i] = 0;

                if(a[uu].size() > 0) a[uu].pop_back();
                if(a[vv].size() > 0) a[vv].pop_back();
                kkk:
                    C -= c[i];
            }
        }
    }
}

void solve(){
    qSort(1, M); // sap xep cac canh theo thu tu tang dan trong so
    //cout << "\nsap xep xong \n";

    for(int i = 1; i<=N; i++)
            r[i] = -1; // ban dau cac nut deu la goc, rank cua cay tuong ung la 1 - co 1 phan tu
    //cout << "\n gan xong!";
    C = 0;
    minC = 1000000;
    for(int i = 1; i<=M; i++){
        choosed[i] = 0; // chua chon canh thu i
        x[i] = 0;
    }
    //cout << "\n gan cong22";
    TRY(1); // tim canh thu nhat cho T;
    cout << minC  <<endl;
    for(int i = 1; i<=N; i++) cout << y[i] << " ";
}

int main(){
    input();
    solve();
}
