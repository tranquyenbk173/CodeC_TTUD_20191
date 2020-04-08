#include<bits/stdc++.h>
#define MAX_N 1005
#define MAX_T 105
using namespace std;

int n, T, D;
int a[MAX_N], tt[MAX_N];
int f[MAX_N][MAX_T]; // f[i][t] la luong hang max lay duoc tai i  voi tgian toi da t
int maxx;

void input(){
    cin >> n >> T >> D;
    for(int i = 1; i<=n; i++) cin >> a[i];
    for(int i = 1; i<=n; i++) cin >> tt[i];
}

void solve(){
    int i, t, ti;
    maxx = 0;

    //khoi tao gia tri trung gian
    for(i = 1;  i<=n; i++){
        for(t = 0; t<=T; t++){
            f[i][t] = 0;
        }
    }

    // khoi tao co so:
    for(t = 0; t<=T; t++)
        if(t >= tt[1]) f[1][t] = a[1];

    //quy hoach dong:
    for(i = 2; i<=n; i++){
        ti = tt[i];
        for(t = 1; t<=T; t++){
            for(int j = 1; j<=D && j<i; j++){
                if(t >= ti && f[i][t] < f[i-j][t-ti] + a[i]){
                    f[i][t] = f[i-j][t-ti] + a[i];
                }
            }

            if(f[i][t] > maxx) maxx = f[i][t];
        }
    }

    cout << maxx<<endl;
}

int main(){
    input();
    solve();
}
