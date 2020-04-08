#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int n, M, x[MAX], s = 0;

void input(){
    cin >> n >> M;
}

int check(int v, int k){
    int s = 0;
    for (int i = 1; i<k; i++){
        s+= x[i];
    }
    if (k<n) return (s+v + n-k)<=M;
    return s+v == M;
}

void solution(){
    for (int i = 1; i<=n; i++){

        cout << x[i] << " ";
    }

    cout << endl;
}

void tryy(int k){
    for (int v = 1; v<=M-n+1; v++){
        if (check(v, k)){
            x[k] = v;
            if (k == n){
                solution();
            }else{
                tryy(k + 1);
            }
        }

    }
}

int main(){
    input();
    tryy(1);
}

