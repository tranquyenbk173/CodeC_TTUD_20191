#include<bits/stdc++.h>
#define MAX 3001

using namespace std;

int n, K;
int c[MAX], a[MAX];

int s[MAX][MAX]; //s[i][k] = luong hang max ma drone lay duoc tai diem i sau k buoc

void input(){
    cin >> n >> K;
    for(int i = 1; i<=n; i++)
        cin >> c[i];
    for(int i = 1; i<=n; i++)
        cin >> a[i];
}

void solve(){
    int Smax = 0;

    for(int i = 1; i<=n; i++){
        for(int k = 0; k<=K; k++){
            s[i][k] = 0;
        }
    }
    s[1][0] = c[1];

    for(int i = 2; i<=n; i++){
        for(int k = 1; k <= K && k<i; k++){
            for(int j = 1; j<i; j++){
                if(a[j] + j >= i && s[j][k-1] > 0)
                    if(s[j][k-1] + c[i] > s[i][k])
                        {
                            s[i][k] = s[j][k-1] + c[i];
                        }
            }
        }
    }

    for(int k = 1; k<=K; k++)
        if(s[n][k] > Smax) Smax = s[n][k];

    cout << Smax;
}

int main(){
    input();
    solve();
}
