#include<bits/stdc++.h>
#define M 1000

using namespace std;

int n, sum, minS;
char x[M], y[M];
char given[3] = {'a', 'b', 'c'};

bool same(int k, int l){// xau gom l ki tu ket thuc tai x[k] co trung voi xau l ki tu truoc do?
    int e1 = k-l, e2 = k;
    while(e2>k-l){
        if(x[e1] != x[e2]) return false;
        e1--;
        e2--;
    }
    return true;
}

bool check(int k){

    for(int l = 1; l<=k/2; l++){
        if(same(k, l)) return false;
    }
    //cout << "k = " << k<< endl;
    return true;
}

void solution(){
    if(sum<minS){
        minS = sum;
    }
    for(int i = 1; i<=n; i++){
        y[i] = x[i];
    }
}

void TRY(int k){
    for(int i = 0; i<3; i++){
        x[k] = given[i]; //cout << "x_" << k <<" =  "<<x[k]<<"-->";
        if(i<2 || (i==2 && sum + 1 + (n-k)/4 <=minS)){
            if(check(k)){
                if(i == 2) sum++;
                if(k == n) solution();
                else TRY(k+1);
                if(i == 2) sum--;
            }
        }
    }
}

int main(){
    cout << "Nhap n: ";
    cin >> n;

    sum = 0;
    minS = 10000;
    TRY(1);

    for(int i = 1; i<=n; i++){
        cout << y[i] << " ";
    }
    cout << endl;
    cout << minS;
}
