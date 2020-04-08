#include<bits/stdc++.h>
#define M 20

using namespace std;

int n, dem = 0;
int x[M][M];
int tn[2*M], tb[2*M], c[M];

void solution(){
    cout << "Truong hop thu "<< dem++;
    for(int h = 1; h<=n; h++){

        cout << "\n\t|";
        for(int cot = 1; cot <=n; cot++){
            if(x[h][cot] == 1){
                cout << "X|";
            }
            else cout << " |";

        }
    }
    cout <<endl<<"________________"<<endl;
}

bool check(int hang, int cot){
    if(c[cot] == 1) return false;
    if(tn[hang+cot] == 1) return false;
    if(tb[hang-cot] == 1) return false;
    return true;
}

void TRY(int k){
    for(int i = 1; i<=n; i++){
        if(check(k, i)){
            x[k][i] = 1;
            tn[k+i] = 1;
            tb[k-i] = 1;
            c[i] = 1;

            if(k == n) solution();
            else TRY(k+1);

            tn[k+i] = 0;
            tb[k-i] = 0;
            c[i] = 0;
            x[k][i] = 0;
        }
    }
}

int main(){

    cout << "Nhap n: ";
    cin >> n;

    TRY(1);
}

