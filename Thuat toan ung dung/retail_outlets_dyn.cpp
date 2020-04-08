#include<bits/stdc++.h>
#define P 1000000007
#define MAX 200
using namespace std;
int n, m; // n la so chi nhanh, m la tong so cua hang ban le
int a[MAX]; // a[i] la so nhan vien ban hang cua chi nhanh i
int f[MAX][550]; // f[i][s] la tong so cach phan cong s cua hang cho i chi nhanh.

void input(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++) cin >> a[i];
}

int addmod(int a, int b){
    a = a % P;
    b = b % P;
    int c = P - a;
    if(c > b) return b+a;
    else return b-c;
}

void solve(){
    int i, j, s, dem;

    //khoi tao bang gia tri trung gian:
    for(i = 1; i<=n; i++){
        for(s = 1; s<=m; s++)
            f[i][s] = 0;
    }

    //khoi tao co so:
    for(s = 1; s<=m; s++){
        if(s % a[1] == 0)
            f[1][s] = 1;
    }

    dem = 0;
    for(i = 1; i<=n; i++){
        if(a[i] == 1) dem++;
        f[i][1] = dem;
    }

    //quy hoach dong:
    for(i = 2; i<=n; i++){
        dem = 0;
        for(j = 1; j<i; j++)
            dem+=a[j];

        for(s = dem + a[i]; s<=m; s++){
            int lim = (s - dem)/a[i];
            for(int t = 1; t<=lim; t++){
                f[i][s] = addmod(f[i][s], f[i-1][s-t*a[i]]);
            }
        }
    }

    cout << f[n][m];
}

int main(){
    input();
    solve();
}


