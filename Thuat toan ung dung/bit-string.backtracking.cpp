#include<bits/stdc++.h>
#define MAX 100

using namespace std;

int n, x[MAX];

void init(){
    cin >> n;
}

void solution(){
    for(int i = 0; i<n; i++)
        cout << x[i];
    cout << endl;
}

int check(){
}

void tryy(int k){
    for (int v = 0; v<=1; v++){
            if ((v == 1) && x[k-1] != 1){
                x[k] = v;
                if (k==n){
                    solution();
                }else{
                    tryy(k+1);
                }
            }

    }
}

int main(){
    init();
    tryy(0);
    return 0;
}
