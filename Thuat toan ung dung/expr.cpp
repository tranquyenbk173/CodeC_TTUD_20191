#include<bits/stdc++.h>
#define P 1000000007
#define M 35

using namespace std;

int n, b, ans = 0;
int a[2][M];
int s[M];
void input(){
    cin >> n >> b;
    for(int i = 1; i<=n; i++) cin >> a[0][i];
    for(int i = 2; i<=n; i++) a[1][i] = -a[0][i];

    a[1][1] = a[0][1];
}

int addmod(int a, int b){
    a = a%P;
    b = b%P;
    int c = P - a;
    if(c > b) return (a+b);
    else return (b-c);
}

void solution(){
    if(s[n] == b) ans = addmod(ans, 1);
}

void TRY(int k) // tong day tinh den so hang thu k.
{
    for(int i = 0; i<=1; i++){
        s[k] = s[k-1] + a[i][k];

        if(k == n) solution();
        else TRY(k+1);

        s[k] = s[k-1] - a[i][k];
    }
}

void solve(){
    s[1] = a[0][1];
    TRY(2);

    cout<< ans;
}

int main(){
    input();
    solve();
}
