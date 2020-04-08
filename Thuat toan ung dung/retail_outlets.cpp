#include<bits/stdc++.h>
#define MAX 110
using namespace std;

int n, m; // n = num of branches, m = num of retail outlets
int a[MAX]; // num of salemen of each branch
int x[MAX]; // num of retail outlets assigned for branch i
int Xmax[MAX]; // max of x[i]
int total, s, COUNT;
void input(){
    total = 0;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        total += a[i];
    }
}

void TRY(int k){
    int lim = Xmax[k];
    for(int i = 1; i<=lim; i++){
        if(s + i*a[k] <= m){
            x[k] = i;
            s += i*a[k];
            if(k == n && s == m) COUNT++;
            else TRY(k+1);

            s -= i*a[k];
        }
    }
}

void solve1(){// lam theo kieu de quy quay lui
    for(int i = 1; i<=n; i++){
        Xmax[i] = (m - total + a[i])/(a[i]);
    }
    COUNT = 0;
    s = 0; // s la tong so cua hang da duoc phan
    TRY(1); // tim x[1]

    cout << COUNT;
}

int main(){
    input();
    solve1();
}
