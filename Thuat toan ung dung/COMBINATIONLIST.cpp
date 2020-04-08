#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int n, m, k;
int a[MAX];

void input(){
    cin >> n >> m >> k;
}

void solve(){
    for(int i = 1; i<=m; i++) a[i] = i;

    int idx = m, dem = 1;
    while(1){

        if(dem == k) break;

        while(a[idx] >= (n-m+idx) && idx >0) idx--;
        if(idx == 0) break;

        a[idx]++;
        for(int i = idx + 1; i<=m; i++) a[i] = a[i-1] + 1;
        idx = m; dem++;
    }

    if(dem == k){
        for(int i = 1; i<=m; i++) cout<< a[i] << " ";
    }
    else cout << -1;
}

int main(){
    input();
    solve();
}
