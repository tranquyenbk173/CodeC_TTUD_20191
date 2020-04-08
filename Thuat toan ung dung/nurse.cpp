#include<bits/stdc++.h>
#define M 1005
#define P 1000000007
using namespace std;
int n, K1, K2;
int s[M][M]; // s[i][k]: so cach len lich voi k khoang lam viec trong i ngay.

int addmod(int a, int b){
    a = a%P;
    b = b%P;
    int c = P-a;
    if(c>b) return (a+b);
    else return (b-c);
}

int main(){
    cin >> n >> K1 >> K2;

    int i, j, k, limK =  n/(K1+1);
    //co so:
    for(i = 1; i<=n; i++){
        s[i][1] = 0;
        if(i>=K1 && i-K1<2) s[i][1] = 1 + i - K1;
        if(i>=K1 && i-K1==2) s[i][1] = 1;
        if(i>=K2 && i-K2 <=2) s[i][1] = max(s[i][1], 1+i-K2);
    }
    for(i = k; k<=limK; k++) s[0][k] = 0;
    //quy hoach dong:
    for(i = 1; i<=n; i++){
        for(k = 1; k<=limK; k++){
            for(j = K1; j<=K2 && j<i-k+1; j++){
                s[i-k+1][k] =  addmod(s[i-k+1][k], s[i-k+1-j][k-1]);
            }
        }
    }
    // tim loi giai:
    int ans = 0;
    for(k = 1; k<=limK; k++){
        ans = addmod(ans, s[n-k+1][k]);
    }

    cout<<ans;
}
