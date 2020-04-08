#include<bits/stdc++.h>
#define MAX 1001
#define P 1000000007
using namespace std;
int n, k1, k2;
int sum, num;
int x[MAX];

int addmod(int a, int b){
    a = a%P;
    b = b%P;
    int c = P-a;
    if(c > b) return (a+b);
    else return (b-c);
}

void input(){
    cin >> n >> k1 >> k2;
}

void solution(int k){
    num++;
//    int i = 1;
//    while(i<=k) cout<< x[i++] <<" ";cout<<endl;
}


void TRY0(int k){
    for(int t = k1; t<=k2; t++){
        if(sum + t < n){
            x[k] = t;
            sum += t + 1;
            if(sum == n || sum == n-1) solution(k);
            else{
                TRY0(k+1);
            }
            sum = sum - t - 1;
        }
    }
}

void TRY1(int k){
    for(int t = k1; t<=k2; t++){
        if(sum + t <= n){
            x[k] = t;
            sum += t;
            if(sum == n || sum == n-1) solution(k);
            else{
                TRY0(k+1);
            }
            sum = sum - t;
        }
    }
}

void solve(){
    num = 0; // num la so ket qua thoa man
    sum = 0;
    TRY1(1); // try first period
    //cout << "\n--\n";
    sum = 0;
    TRY0(1);

    cout<< num;
}

int main(){
    input();
    solve();
}
