#include<bits/stdc++.h>
#define MAX 10001

using namespace std;

int n;
char a[MAX];

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];

    int k = n;
    while(a[k] == '1') k--;
    if(k > 0){
        a[k] = '1';
        for(int i = k+1; i<=n; i++) a[i] = '0';
        for(int i = 1; i<=n; i++) cout<< a[i];
    }else{
        cout << -1;
    }

}
