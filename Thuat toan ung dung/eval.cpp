#include<bits/stdc++.h>
#define M 200001

int n, a[M], b[M];

void input(){
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 1; i<n; i++) cin >> b[i];
}

void solve(){
    int p1, p2;
    int is, ie; // vị trí bắt đầu và kết thúc của chuỗi phép nhân:

    is = 0;
    while (is <=n-1){
    while(is<=n-1){
        if(b[is] == 2) break;
        else is ++;
    }

    p1 = a[is-1]*a[is];
    while(b[is+1] == 2){
        p1 *= a[is+1];
        is++;
    }
    if(is<n+1) ie = is;

    for(int i = is-1; i>=1; i--){
        if(b[i] == 0) p1 = a[i-1] - p[1];
        else if(b[i] == 1) p1 = p1 + a[i-1];
    }


}

int main(){
    input();
    solve();
}
