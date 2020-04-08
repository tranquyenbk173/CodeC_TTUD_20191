#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

int n, a[MAX][MAX];

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    //int res;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i != j && a[i][j] ==0){
                cout << 0;
                return 0;
            }
        }
    }

    cout << 1;
}
