#include<bits/stdc++.h>
#define M 25
using namespace std;
int n; // num of courses
int m; // num of teachers
int h[M]; // h[i] - duration of course i
int t[M][M]; // t[0][i] - num of teachers who can teach course i, t[j][i], j>0: index of teacher
int a[M][M]; // conflict matrix
int x[M]; // x[i] teacher assigned for course i;
int sumT, sum;

void input(){
    cin >> n >> m;
    int i, j, d;
    for(i = 1; i<=n; i++) cin >> h[i];
    for(i = 1; i<=n; i++){
        cin >> d;
        t[i][0] = d;
        for(j = 1; j<=d; j++) cin >> t[i][j];
    }
    for(i = 1; i<=n; i++){
        for(j = 1; j<=n; j++) cin >> a[i][j];
    }
}

void solve(){

}

int main(){
    input();
    solve();
}
