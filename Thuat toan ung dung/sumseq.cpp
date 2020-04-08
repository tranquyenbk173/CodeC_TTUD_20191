#include<iostream>
#define MAX 100000
using namespace std;

int M = 1000000007;

int addmod(int a, int b){
    a = a % M;
    b = b % M;
    int c = M - a;
    if (c > b) return (b + a);
    else  return (b - c);
}

int main(){
    long n, a[MAX], S = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i<n; i++){
        S = addmod(S, a[i]);
    }

    cout << S;
}

