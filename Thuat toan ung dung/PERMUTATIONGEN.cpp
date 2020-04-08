#include<bits/stdc++.h>
#define MAX 10001

using namespace std;
int n, a[MAX];

void SWAP(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int main(){
    // input
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];

    //sinh hoan vi
    int j = n-1;
    while(j>0 && a[j] > a[j+1]) j--;

    if(j>=1){
        int i = n;
        while(a[i] < a[j]) i--;
        SWAP(a[j], a[i]);

        int k = j+1; i = n;
        while(k<i){
            SWAP(a[k], a[i]);
            k++; i--;
        }
        for(int i = 1; i<=n; i++) cout<< a[i] << " ";
    }
    else cout << -1;


}
