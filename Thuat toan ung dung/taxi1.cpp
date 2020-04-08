#include<bits/stdc++.h>
#define MAX 12

using namespace std;


int n, c[MAX + MAX + 1][MAX + MAX + 1], cur_len, output, cmin;
int visit[MAX+1], x[MAX + MAX + 1];

void input(){
    cin >> n;
    cmin = 10000;
    for (int i = 0; i<= 2*n; i++)
        for (int j = 0; j<= 2*n; j++){
            cin >> c[i][j];
            if (c[i][j] < cmin) cmin = c[i][j];
        }
}

void init(){
    for(int i = 0; i<= n; i++)
        visit[i] = 0;

    visit[0] = 1;
    x[0] = 0;

    output = 10000;
    cur_len = 0;
}

void solution(){
    if (cur_len + c[x[n+n]][0] < output)
        output = cur_len + c[x[n+n]][0];
}

void TRY(int k){
    for(int u = 1; u<= n; u++){
        if (visit[u] == 0 && cur_len + c[x[k-1]][u] + cmin * (n+n-k+1) < output){
            x[k] = u;
            x[k+1] =  u+n;
            visit[u] = 1;
            cur_len += c[x[k-1]][u] + c[u][u+n];

            if (k == n+n-1)
                solution();
            else TRY(k + 2);
            visit[u] = 0;
            cur_len = cur_len - c[x[k-1]][u] - c[u][u+n];
        }

    }
}

void solve(){
    int i;
    TRY(1);
}

int main(){
    input();
    init();
    solve();
    cout << output;
}
