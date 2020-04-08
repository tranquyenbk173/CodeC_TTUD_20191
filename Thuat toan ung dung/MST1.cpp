#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n, m;
int u[MAX], v[MAX];
long long int w[MAX];
int r[MAX]; // r[i] la cha cua i trong cay kiem tra logic
int t; // so canh cua cay;

void input(){
    cin >> n >> m;
    int a, b;
    long long int d;
    for(int i = 1; i<=m; i++){
        cin >> a >> b >> d;
        u[i] = a;
        v[i] = b;
        w[i] = d;
    }
}

void SWAP(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
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
                temp = w[e];
                w[e] = w[s];
                w[s] = temp;
                SWAP(u[s], u[e]);
                SWAP(v[s], v[e]);
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
    r[u] = res;
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

void solve(){
    qSort(w, 1, m); // sap xep cac canh

    for(int i = 1; i<=n; i++) r[i] = -1; // ban dau cac nut deu la goc, rank cua cay tuong ung la 1 - co 1 phan tu
    //cout << "here!";
    t = 0;
    long long int res = 0;
    for(int i = 1; i<=m; i++){ // xet canh thu i
        int a = root(u[i]);
        int b = root(v[i]);
        if(a != b){
            res += w[i];
            MERGE(a, b);
            t++;
            if(t == n-1) break;
        }
    }

    cout << res;
}

int main(){
    input();
    solve();
}
