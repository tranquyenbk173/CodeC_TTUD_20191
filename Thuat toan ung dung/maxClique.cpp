#include<bits/stdc++.h>
#define MAX 15
using namespace std;

int Nv, Me;
int a[MAX][MAX];
int degree[MAX];

void input(){
    cin >> Nv >> Me;
    int u, v;
    for(int i = 1; i<=Nv; i++) degree[i] = 0;
    for(int i = 0; i<Me; i++){
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
        degree[u] ++;
        degree[v] ++;
    }
}

void solve(){
    int minI, minD;
    do{
        minI = 1;
        minD = Nv+1;
        int i, d = 0;
        for(i = 1; i<=Nv; i++){
            if(degree[i] != 0 && degree[i] < minD){
                minD = degree[i];
                minI = i;

            }else if (degree[i] > minD) d++;
        }

        if(d==0){
            // tuc la khi bac cua cac dinh con lai bang nhau:
            break;
        }

        // Neu khong thi loai bo dinh i cung cac canh ke khoi do thi:
        degree[minI] = 0;
        for(i = 1; i<=Nv; i++){
            if(i != minI && a[i][minI] != 0){
                degree[i]--;
            }
        }

    }while(1);

    int sum = 0;

    for(int i = 1; i<=Nv; i++){
        if(degree[i] == minD) sum++;
    }
    cout << sum;
}

int main(){
    input();
    solve();
}
