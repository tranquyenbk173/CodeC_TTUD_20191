#include<bits/stdc++.h>
#define M 1000

using namespace std;

int n, sum, dem;
int x[M];

void solution(){
    for(int i = 1; i<=dem; i++) cout << x[i]<<" ";
    cout << endl;
}

void TRY(int k){
    int t = x[k-1];
    for(int i = t; i<=n-sum; i++){
        cout << "x["<<k<<"] = "<< x[k] <<endl;
        if(i + sum <=n){
            x[k] = i;
            sum+=x[k]; dem++;

            if(sum == n) solution();
            else TRY(k+1);

            sum-=x[k]; dem--;
        }

    }
}

int main(){
    cout << "Nhap n: ";
    cin >> n;

    dem = sum = 0;
    x[0] = 1;
    TRY(1);
}
