#include<bits/stdc++.h>
#define MAX 13
using namespace std;

int b[MAX][MAX];
int n, m;
int num[1001], dem, id; // so cach dat quan thoa man
int x[MAX]; // xi = chi so cot cua quan hau hang thu i
int c[MAX]; // danh dau cot bi chiem
int dn[MAX*2], db[MAX*2]; // danh dau duong cheo bi chiem

void init(){
    for(int i = 1; i<=n; i++){ // khoi tao ban co moi
        for(int j = 1; j<=n; j++)
            b[i][j] = 0;
    }

    for(int i = 1; i<=n; i++) c[i] = 0;
    for(int i = 1; i<=n+n; i++){
        dn[i] = db[i] = 0;
    }
}

bool check(int hang, int cot){
    return b[hang][cot] == 0 && c[cot] == 0 && \
    dn[hang-cot+n] == 0 && db[hang+cot] == 0;
}

void solution(){
    dem++;
}

void TRY(int k){ // dat hau vao hang k:
    for(int i = 1; i<=n; i++){ // cot
        if(check(k, i)){
            b[k][i] = 1;
            c[i] = 1;
            dn[k-i+n] = 1;
            db[k+i] = 1;

            if(k == n) solution();
            else TRY(k+1);

            b[k][i] = 0;
            c[i] = 0;
            dn[k-i+n] = 0;
            db[k+i] = 0;
        }

    }
}

void solve(){
    dem = 0;
    TRY(1);
    num[id++] = dem;
}

int main(){
    int i, j;
    id = 0;
    while(1){
        cin >> i >> j;
        if(i == 0 && j == 0) break;
        n = i; m = j;

        init();

        for(int k = 1; k<=m; k++){
            cin >> i >> j;
            b[i][j] = 1;
        }
        solve();
    }

    for(int i = 0; i<id; i++) cout << num[i] << endl;
}
