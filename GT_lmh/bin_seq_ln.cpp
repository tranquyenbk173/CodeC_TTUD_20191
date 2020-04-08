#include<bits/stdc++.h>
#define M 1000
using namespace std;

int N, L, start;
int x[M] = {0, 1, 0, 1, 0, 1, 0, 1};

void solution(){
    for(int k = 1; k<=N; k++){
        cout << x[k] << " ";
    }
    cout << endl;
}

int check(int x[], int i, int start, int k){
    x[k] = i;
    int start2 = start + L;
    int e = start2;
    while(start < e){
        if(x[start] != x[start2]){
//            cout << "Day dung: ";
//            for(int j = 1; j<=k; j++) cout << x[j]<< " ";
//            cout << endl;
            return 1;
        }
        start ++;
        start2++;
    }

    return 0;
}

void TRY(int k){
    for(int i = 0; i<=1; i++){
        if(k <= 2*L-1 || (k > 2*L-1 && check(x, i, k-2*L+1, k))){
            x[k] = i;

            if(k == N) solution();
            else TRY(k+1);
        }
    }
}

int main(){
    cout << "Nhap n, l: ";
    cin >> N >> L;
    TRY(1);
    //L = 2;
    //cout << check(x, 1, 1, 5)<<endl;
}
