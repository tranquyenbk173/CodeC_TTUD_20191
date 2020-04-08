#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int n, m, a[MAX];

int main(){
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        cin >> a[i];
    }

    int idx = m;
    while(a[idx] == (n+idx-m) && idx > 0) idx--;
    if(idx > 0){
        a[idx] ++;
        for(int j = idx+1; j<=m; j++) a[j] = a[j-1] + 1;

        for(int i = 1; i<=m; i++) cout << a[i] << " ";
    }else{
        cout << -1;
    }
}
