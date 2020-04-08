#include<bits/stdc++.h>
#define M 2000
using namespace std;
int n, m;// n la so dong, m la so cot
char a[M][M]; // matrix island;
int sum, max_area, area;
int X[4] = {-1, 1, 0, 0};
int Y[4] = {0, 0, -1, 1};

void input(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
       cin >> a[i];
    }
}

int check(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (a[x][y] == '0') return 0;
    return 1;
}

void dfs(int x, int y){
    int nextX, nextY;
    area++;
    a[x][y] = '0';

    for(int i = 0; i<4; i++){
        nextX = x + X[i];
        nextY = y + Y[i];
        if(check(nextX, nextY))
            dfs(nextX, nextY);
    }

}

void solve(){
    sum = 0;
    max_area = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j] == '1'){
                area  = 0;
                sum++;
                dfs(i, j);

                if(area > max_area) max_area = area;
            }
        }
    }

    cout << sum << endl << max_area;

}

int main(){
    input();
    solve();
}
