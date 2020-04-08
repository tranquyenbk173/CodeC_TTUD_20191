#include<bits/stdc++.h>
#define MAX 35
using namespace std;

int n, m, k;
int u[MAX], v[MAX];
long long int w[MAX];
int r[MAX]; // r[i] la cha cua i trong cay kiem tra logic
int t; // so canh cua cay;
long long int res = 0;
set<int> Vt;

void input(){
    cin >> n >> m >> k;
    for(int i = 1; i<=m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }
}

void qSort(long long int w[], int left, int right)
{
    if (left < right) // Neu day co nhieu hon mot phan tu
    {
        long long int pivot = w[(left + right)/2];
        int s = left, e = right;
        long long int temp;

        while (s <= e){
            while (w[s] < pivot) s++;
            while (w[e] > pivot) e--;
            if (s <= e){
                swap(w[e], w[s]);
                swap(u[s], u[e]);
                swap(v[s], v[e]);
                s++; e--;
            }
        }
        qSort(w, left, e);
        qSort(w, s, right);
    }
}

int root(int u){ // disjoin set
    if(r[u] < 0) return u;
    int res = root(r[u]);
    //r[u] = res;
    return res;
}

void MERGE(int ru, int rv){
    if(r[ru] < r[rv]){// neu so con cua u nhieu hon v
        r[ru] += r[rv];
        r[rv] = ru;
    }
    else{
        r[rv] += r[ru];
        r[ru] = rv;
    }
}

void TRY(int t){
    for(int i = k+1; i<=m; i++){
        // thu them canh k+1 vao cay:
        int a = root(u[i]);
        int b = root(v[i]);
        if(a != b){
            Vt.insert(u[i]);
            Vt.insert(v[i]);
            res += w[i];
            MERGE(a, b);
        }

        if(checkOk()){

        }
}

int checkOk(){
    int rr = root(u[1]);
    for (set<int> ::iterator it = Vt.begin(); it!=Vt.end(); ++it)
    if(root(*it) != rr){
            return 0;
    }
    return 1;
}

void solve(){

    qSort(w, 1, m); // sap xep cac canh

    for(int i = 1; i<=n; i++) r[i] = -1; // ban dau cac nut deu la goc, rank cua cay tuong ung la 1 - co 1 phan tu

    t = 0; // so canh cua cay khung

    for(int i = 1; i<=k; i++){ // xet canh thu i
        int a = root(u[i]);
        int b = root(v[i]);
        if(a != b){
            Vt.insert(u[i]);
            Vt.insert(v[i]);
            res += w[i];
            t++;
            MERGE(a, b);
//            if(t >= k && checkOk()){
//                cout << res;
//                return;
//            }
        }else{

            cout << -1;
            return;

        }
    }

    if(checkOk() == 1){
        cout << res;
        return;
    }
    else{
        TRY(k+1); // tim them canh thu k+1 cho cay.
    }
}

int main(){
    input();
    solve();
}
