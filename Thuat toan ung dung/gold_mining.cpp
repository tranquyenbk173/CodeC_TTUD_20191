#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, l1, l2; // INPUT
int a[MAX]; // INPUT
int s[MAX]; // s[i]: luong vang lon nhat tu mo 1 den mo i, co chua mo i;
int ans;

void input(){
    cin >> n >>  l1 >>  l2;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
}

void init(){
    ans = 0;
    for(int i = 1; i<=l1; i++){
        s[i] = a[i];
        if(ans < s[i]) ans = s[i];
    }

}

void solve(){
    init();

    for(int i = l1+1; i<=n; i++){
        s[i] = 0;
        int k = i-l2;
        while(k<1) k++;
        for(int j = k; j<=i-l1; j++){
            if (a[i] + s[j] > s[i]) s[i] = s[j] + a[i];
        }

        if(ans < s[i]) ans = s[i];
    }

    cout << endl<<ans;
}

int main(){
    input();
    solve();
}
