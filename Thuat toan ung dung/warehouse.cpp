#include<bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, T, D; // input
int a[MAX], t[MAX], amax;
int x[MAX];
int c, maxC, tt;
int visited[MAX];

void input(){
    cin >> N >> T >> D;
    amax = -10000;
    for(int i = 1; i<=N; i++){
        cin >> a[i];
        if(amax < a[i]) amax = a[i];
    }

    for(int i = 1; i<=N; i++){
        cin >> t[i];
    }

}

void solution(){
    if(c > maxC)
        maxC = c;
}

void TRY(int k){ // tim x[k]
    for(int i = 1; i<=N; i++){
        if(visited[i] == 0){
            if(tt + t[i] < T && (i - x[k-1] <= D) && c + a[i] + amax*(N-i) > maxC){
                x[k] = i; cout << "ok!";
                c  += a[i];
                tt += t[i];
                if(k == N) solution();
                else TRY(k+1);
                c -=a[i];
                tt -= t[i];
            }
        }

    }
}

void solve(){
    c = maxC = 0;
    tt = 0;
    for(int i = 1; i<=N; i++) visited[i] = 0;
    TRY(1);
    cout << maxC;
}

int main(){
    input();
    solve();
}
