#include<bits/stdc++.h>
#define M 25

using namespace std;

int n, dem = 0;
int site[M][M];
int h[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int c[8] = {-2, 2, -2, 2, -1, 1, -1, 1};

void solution(){
    for(int i = 1; i<=n; i++){
            cout << endl;
        for(int j = 1; j<=n; j++){
            cout <<site[i][j]<< " \t";
        }
    }
}

void dichuyen(int x, int y){
    site[x][y] = ++dem;

    if(dem == n*n){
        solution();
        exit(1);
    }

    for(int i = 0; i<8; i++){
        int hang = x + h[i];
        int cot = y + c[i];

        if(hang >=1 && hang <=n && cot >=1 && cot <= n && site[hang][cot] == 0)
            dichuyen(hang, cot);
    }
    site[x][y] = 0;
    dem--;
}

int main(){
    cout << "Nhap n: ";
    cin >> n;

    dichuyen(1, 1);
    if(dem <n*n) cout<< "Vo nghiem!";
}
