#include<bits/stdc++.h>
#define M 1000
using namespace std;

int n, depth;
char x[M];
int C = 0; // C la so ngoac dong can them
char g[2] = {'(', ')'};

int d(int lim){
    int maxx = 0, dd = 0;
    for(int i = 1; i<=lim; i++){
        if(x[i] == '(') dd++;
        else dd--;
        if(maxx < dd) maxx = dd;
    }
    return maxx;
}

void solution(){
    if(d(n) != depth) return;
    for(int  i = 1; i<=n; i++) cout <<x[i] << " ";
    cout <<endl;
}

void TRY(int t){// tim ki tu thu t
    if(C < n-t+1 && d(t-1) < depth){ // (n-t+1) la so ki tu can dien.
        x[t] = g[0];
        C++;

        if(t == n) solution();
        else TRY(t+1);

        C--;
    }
    if(C > 0){
        x[t] = g[1];
        C--;

        if(t == n) solution();
        else TRY(t+1);

        C++;
    }
}

int main(){
    cout <<"Nhap n, depth:";
    cin >> n >> depth;
    //cout<< g[0] << g[1];

    TRY(1);
}
