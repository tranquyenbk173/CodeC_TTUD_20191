#include<bits/stdc++.h>
#define M 100000
#define F -1000000

using namespace std;
int n, a[M];


void input(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];
}

void solve(){
    int** s; //  trong luong day chan ket thuc tai i
    s = new int*[n];
    for(int i = 1; i<=n; i++){
        s[i] = new int[n];
    }

    for(int i = 1; i<=n; i++)
        s[i][i] = a[i];
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            s[i][j] = s[i][j-1] + a[j];
        }
    }

    int maxx = F;
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++)
        if(s[i][j] % 2 == 0 && s[i][j] > maxx) maxx = s[i][j];

    }

    cout << maxx;
}

int main(){
    input();
    solve();
}
