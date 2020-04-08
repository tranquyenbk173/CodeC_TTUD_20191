#include<bits/stdc++.h>

using namespace std;

int n, c[17][17], minS, s, cmin;
int visited[17];
int x[17];

void input(){
    cin >> n;
    minS = cmin = 10000;
    for (int i = 0; i<n+1; i++)
    {
        for (int j = 0; j<n+1; j++){
            cin >> c[i][j];
            if (i != j){
                if (cmin > c[i][j]) cmin = c[i][j];
        }
        }

    }

    for (int i = 0; i<n+1; i++){
        visited[i] = 0;
    }
}

void solution(int v){
    if (s + c[v][0] < minS) minS = s + c[v][0];
}

void TRY(int k){
    for (int v = 1; v < n+1; v++){
        if (visited[v] == 0){
           x[k] = v; s += c[x[k-1]][v];
           visited[v] = 1;
           if ( k == n && s < minS)
                solution(v);
           else {
                if (s + cmin*(n-k+1) < minS)
                    TRY(k+1);
           }
           s-=c[x[k-1]][v];
           visited[v] = 0;
        }
    }
}

int main(){
    input();
    s = 0;
    minS = 100000;
    x[0] = 0;
    TRY(1);
    cout << minS;
}
