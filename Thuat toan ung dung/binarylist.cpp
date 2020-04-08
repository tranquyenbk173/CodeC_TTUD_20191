#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int n, k, i;
int a[MAX];

void input(){
    cin >> n >> k >> i;
}

int check(){
    int dem = 0, m = 0;
    for(int id = 1; id<=n; id++){
        if(a[id] == 0){
            dem++;
            if(m < dem) m = dem;
        }else dem = 0;
    }

    if(m < i) return 1;
    else return 0;
}

void solve(){
    for(int id = 1; id<=n; id++){
        if(id % i) a[id] = 0;
        else a[id] = 1;
    }

    int dem = 1;
    int id = n;
    while(1){
        if(dem == k) break;
        while(a[id] == 1 && id > 0) id--;
        if(id == 0) break;

        a[id] = 1;
    for(int j = id+1; j<=n; j++) a[j] = 0;
    if(check()) dem++;
    id = n;
    }

    if(dem == k){
        for(int j = 1; j<=n; j++) cout << a[j] << " ";
    }
    else cout << -1;
}

int main(){
    input();
    solve();
}
