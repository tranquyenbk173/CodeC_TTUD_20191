#include<bits/stdc++.h>
#define M 1000

using namespace std;

int n, T;
int x[M], xx[M];

void solution(){
    int maxx = 1, minn = n;
    while(xx[maxx] == 0) maxx++;
    maxx = x[maxx];
    while(xx[minn] == 0) minn--;
    minn = x[minn];

    if(minn - maxx <= T){
        for(int i = 1; i<=n; i++){
            if(xx[i] == 1) cout<< x[i] << " ";
        }
        cout << endl;
    }
}

void TRY(int k){

    for(int i = 0; i<= 1; i++){
        xx[k] = i;

        if(k == n) solution();
        else TRY(k+1);
    }
}

int main(){
    cout << "Nhap n, T: ";
    cin >> n >> T;

    for(int i = 1; i<=n; i++){
        x[i] = i;
    }

    TRY(1);
}
