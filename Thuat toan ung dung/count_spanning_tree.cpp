#include<bits/stdc++.h>
#define MAX 30
int n, m;
int u[MAX] v[MAX];
int countST = 0;
long long int res = 0;
int choosed[MAX]; // danh dau mot canh nao do da duoc chon
void input(){
    cin >> n >> m;
    for(int i= 1; i<=m; i++){
        cin >> u[i] >> v[i];
    }
}

void TRY(int k){// tim ST thu k:
     for(int i = 1; i<=m; i++){ // xet canh thu i
        int a = root(u[i]);
        int b = root(v[i]);
        if(a != b){
            res += w[i];
            MERGE(a, b);
            t++;
            if(t == n-1) break;
}

void solve(){
    for(int i = 1; i<=m; i++) choosed[i] = 0; // danh dau
    TRY(1); // tim bat dau tu canh thu nhat
    cout << countST;
}

int main(){
    input();
    solve();
}
