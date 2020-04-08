#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n, a[MAX]; //input
int maxW;
int s[MAX];

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
}

void solve(){
    maxW = -1000000;
    for(int i = 1; i<=n; i++){
        if(s[i-1] >=0){
            s[i] = s[i-1] + a[i];
        }
        else{
            s[i] = a[i];
        }

        if(s[i] > maxW) maxW = s[i];

    }

    cout << maxW;
}

int main(){
    input();
    solve();
}
