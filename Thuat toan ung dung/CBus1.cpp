#include<bits/stdc++.h>
#define MAX 100

using namespace std;

int n; // num of requests
int cap; // num of places of the bus
int c[2*MAX + 1][2*MAX + 1]; // distance matrix
int cmin;

int x[MAX];
int appear[MAX]; // appear[v] = 1 indicates v has appeared
int load;
int f;
int f_best;

void input(){
    cin >> n >> cap;
    cmin = 100000;

    for (int i = 0; i<=2*n; i++){
        for (int j = 0; j<=2*n; j++){
            cin >> c[i][j];
            if (i != j && c[i][j] < cmin)
                cmin = c[i][j];
        }
    }
}


int check(int v, int n){
    if (appear[v] == 1) return 0;

    if (v>n){
        if(!appear[v-n]) return 0;
    }else{
        if (load + 1 > cap) return 0;
    }
    return 1;
}

void solution(){
    if (f  + c[x[2*n]][0] < f_best){
        f_best = f + c[x[2*n]][0];
    }
}

void TRY(int k){
    for (int v = 1; v<=2*n; v++){
        if (check(v, n)){
            x[k] = v;
            f += c[x[k-1]][v];
            if (v<=n) load++;
            else load--;
            appear[v] = 1;
            if (k == 2*n) solution();
            else{
                if(f + (2*n-k+1)*cmin < f_best)
                    TRY(k+1);
            }
            if (v <= n) load--;
            else load ++;
            appear[v] = 0;
            f-=c[x[k-1]][v];
        }
    }
}

void solve(){
    load = 0;
    f = 0;
    f_best = 1000000;

    for(int i = 1; i<=2*n; i++){
        appear[i] = 0;
    }
    x[0] = 0;
    TRY(1);
    cout << f_best;
}

int main(){
    input();
    solve();
}
