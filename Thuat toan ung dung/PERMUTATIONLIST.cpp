#include<bits/stdc++.h>
#define MAX 10001

using namespace std;

int n, k;

void input(){
    cin >> n;
    cin >> k;
}

void SWAP(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void solve(){
    int dem = 1; //dem so thu tu cua hoan vi
    int a[n+1]; // mang chua hoan vi
    for(int i = 1; i<=n; i++) a[i] = i;
    int idx = n-1;
    while(1){// khi chua xet het
        if(dem == k) break;

        idx = n-1;
        while(a[idx] > a[idx + 1] && idx>0) idx--;
        if(idx == 0) break;

        int j = n;
        while(a[j] < a[idx]) j--;
        SWAP(a[j], a[idx]);

        int k = idx + 1; j = n;
        while(k<j){
            SWAP(a[k], a[j]);
            k++; j--;
        }
        dem++;
    }

    if(dem != k) cout<< -1;
    else{
        for(int i = 1; i<=n; i++) cout<< a[i] << " ";
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    input();
    solve();
}
