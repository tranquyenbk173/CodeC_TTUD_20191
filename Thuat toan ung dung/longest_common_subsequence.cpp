#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int n, m; // length of X, Y sequence
int x[MAX], y[MAX];
int s[MAX][MAX]; // s[i][j] = longest length of (x1 -> xi) and (y1 -> yj)

void input(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> x[i];
    }
    for(int j =1; j<=m; j++){
        cin >> y[j];
    }
}

void init(){
    int i, j;
    s[0][0] = 0;

    i = 1;
    for(j = 1; j<=m; j++){
            if(x[i] == y[j]) {
                    s[i][j] = 1;
        //            cout << i << " - " << j;
            }
            else s[i][j] = s[i][j-1] >0? s[i][j-1]:0;
    }



    j = 1;
    for(i = 1; i<=n; i++){
            if(x[i] == y[j]) s[i][j] = 1;
            else s[i][j] = max(s[i-1][j], s[i][j-1]);
    }


}

void solve(){
    init();

//    cout << "ok1"<<endl;

    for(int i = 2; i<=n; i++){
        for(int j = 2; j<=m; j++){
            if(x[i] == y[j]) s[i][j] = s[i-1][j-1] + 1;
            else s[i][j] = max(s[i-1][j], s[i][j-1]);
        }
    }

//        for(int i = 1; i<=n; i++){
//            cout << endl;
//        for(int j = 1; j<=m; j++){
//            cout << s[i][j] << " ";
//        }
//    }


    cout << endl<< s[n][m];
}

int main(){

    input();
    solve();
}


