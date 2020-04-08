#include<bits/stdc++.h>
#define MAX 205
using namespace std;

int n, m, k, q;
int w1[55][55];
int w2[55][55];
int choosed[55];
int W1, W2, minW1, minc1, minc2;
int x[55]; // luu vet

void input(){
    cin >> n >> m >> k >> q;
    int u, v, w11, w22;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            w1[i][j] = w2[i][j] = 0;
        }
    }

    for(int i = 1; i<=m; i++){
        cin >> u >> v >> w11 >> w22;
        w1[u][v] = w1[v][u] = w11;
        w2[u][v] = w2[v][u] = w22;
        if(minc1 > w11) minc1 = w11;
        if(minc2 > w22) minc2 = w22;
    }
}

void solution(){
    //cout << "w1 = "<< W1<< " minW1 = " << minW1;
    if(W1 < minW1 && W2 <=q){
        minW1 =  W1;
//            cout <<endl;
//        for(int i = 1; i<=k+1; i++) cout << x[i] << " ";
//        cout << "---" << minW1;
    }

}

void TRY(int t){ // thu x[t]
    int u = x[t-1];
    for(int v = 1; v<=n; v++){
        if (w1[u][v] != 0){
        if(choosed[v] == 0 && (W1 + minc1*(k-t+1) < minW1)&& (minc2*(k-t+1) + W2 <=q)){
            choosed[v] = 1;
            x[t] = v;
            W1 += w1[u][v];
            W2 += w2[u][v];

            if(t == k){
                // kiem tra xem v co ke voi x[1]?
                int vv = x[1];
                    if(w1[v][vv] != 0){
                        if(W1 + w1[v][vv] < minW1 && W2 + w2[v][vv]<=q){
                            minW1 = W1 + w1[v][vv];
                        }
                    }

            }
            if(t == k+1) solution();
            else TRY(t+1);

            choosed[v] = 0;
            W1 -= w1[u][v];
            W2 -= w2[u][v];
        }
    }
    }
}

void solve(){
    W1 =  W2 = 0; // tong trong so w1, w2 tren duong di
    minW1 = 1000000;
    for(int i = 1; i<=n; i++){
        choosed[i] = 0;
    }
    for(int i = 1; i<=n; i++){
        x[1] = i; //cout << endl << "chon x1 = " << i;
        choosed[i] = 1;
        TRY(2);
        choosed[i] = 0;
    }

    cout << minW1;
}

int main(){
    input();
    solve();
}
