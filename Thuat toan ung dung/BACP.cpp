#include<bits/stdc++.h>
#define MAX_N 20
#define MAX_M 20

using namespace std;

int n; // num of courses
int m; // num of periods
int c[MAX_N]; // vector of credits
int a[MAX_N][MAX_N]; // prerequisite matrix

int choosePeriod[MAX_N]; // choosePeriod[i] = j -> course i choosed for Period j
int load[MAX_M]; // load[j] = load of period j;

int f_best;

void input(){
    cin >> n >> m;
    int i, j;
    for (i = 1; i<=n; i++)
        cin >> c[i];
    for(i = 1; i<=n; i++){
        for (j = 1; j<=n; j++){
            cin >> a[i][j];
        }
    }
}

int check(int k, int p){// Kiem tra xem khoa k co xep vao ki p duoc hay khong?
    for (int i = 1; i<=n; i++){
        if (a[k][i] == 1){
            if(choosePeriod[i] >= p)
                return 0;
        }
    }
    return 1;

}

void solution(){
    int temp = 0;
    for(int i = 0; i<=m; i++){
        if (load[i] > temp) temp = load[i];
    }
    if(temp < f_best) f_best = temp;
}

void TRY(int k){
    for (int i = 1; i<=m; i++){
        if (check(k, i)){
            choosePeriod[k] = i;
            load[i] += c[k];

            if (k == n) solution();
            else TRY(k+1);

            load[i] -= c[k];
        }
    }
}

void solve(){
    f_best = 10000;
    for(int i = 1; i<=m; i++){
        load[i] = 0;
    }

    TRY(1);

    cout << f_best;
}

int main(){
    input();
    solve();
}
