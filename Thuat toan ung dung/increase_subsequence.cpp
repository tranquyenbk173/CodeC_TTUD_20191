#include<bits/stdc++.h>

#define MAX 10001

using namespace std;

int n;
int x[MAX];
int s[MAX];


void input(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> x[i];
    }
}

void solve(){
    s[1] = 1; // init
    int ans = s[1];

    for(int i = 2; i<=n; i++) // tim do dai day con tang lon nhat cua day s[i]:
    {
        s[i] = 1; // day co it nhat mot phan tu thoa man la x[i];
        for(int j = 1; j<i; j++){
            if(x[j] < x[i] && s[i] < s[j] + 1){
                s[i] = s[j] +1;
            }
        }
        if(ans < s[i]) ans = s[i];

    }

    cout << ans;
}

int main(){
    input();
    solve();
}
