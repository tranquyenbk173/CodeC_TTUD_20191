#include<bits/stdc++.h>
#define M 1001

using namespace std;

int n, a[M];

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];


    int dem = 0;
    for(int i = 1; i<n; i++){
        for(int j = i+1; j<=n; j++){
            if(a[i] < a[j]) dem++;
        }
    }

    cout<< dem;
}
