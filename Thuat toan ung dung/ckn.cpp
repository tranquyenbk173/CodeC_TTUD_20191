#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int n, k, m;
int T;
int c[MAX][MAX];
int ans[MAX], d;

int addmod(int a, int b, int m){
    a = a%m;
    b = b%m;
    int c = m-a;
    if(c>b) return (a+b);
    else return (b-c);
}

void solve(int n, int k, int m){
    for(int j = 2; j<=n; j++){
        for(int i = 1; i<j; i++){
            if(c[i][j] == 0) c[i][j] = addmod(c[i-1][j-1], c[i][j-1], m);
        }
    }

    ans[d++] = c[k][n];
}

int main(){
    cin >> T;
    d = 0;
    for(int i = 0; i<=MAX; i++) {c[0][i] = 1; c[i][i] = 1;}
    c[1][1] = 1;
    for(int i = 1; i<=T; i++){
        cin >> n >> k >> m;
        solve(n, k ,m);
    }

    for(int i = 0; i<d; i++) cout << ans[i] <<endl;
}
