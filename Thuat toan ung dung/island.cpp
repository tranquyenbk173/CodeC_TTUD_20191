#include<bits/stdc++.h>

#define MAX 2001

using namespace std;

int n, m; // hang, cot cua ma tran anh
int a[MAX][MAX]; // ma tran diem anh
int qx[500000], qy[500000], head, tail; // hang doi

int x, y; // toa do hien tai dang xet - pop tu hang doi
int maxS, num, s;

//Cac thao tac voi hang doi:

void push(int i, int j){
    if (a[i][j] == 0) return;
    qx[++head] = i;
    qy[head] = j;
    a[i][j] = 0;
    s++;
    //cout << "push" << i << "," << j<< endl;
}

void pop(){
    x = qx[tail];
    y = qy[tail++];
}

//end of Q

void input(){
    char s[m  + 1];
    cin >> m >> n;

    for (int i = 1; i<= m; i++){
        cin >> s;
        for (int j = 1; j<=n; j++){
            if (s[j-1] == '0') a[i][j] = 0;
            else if (s[j-1] == '1') a[i][j] = 1;
        }
    }
}

void BFS(int i, int j){
    head = tail = 0;
    qx[0] = i; qy[0] = j;
    s++; a[i][j] = 0;

    while(head >= tail){
        pop();
        push(x, y+1);
        push(x, y-1);
        push(x+1, y);
        push(x-1, y);
    }
}

int solve(){
    maxS = 0;
    num = 0;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(a[i][j] == 1){
                num ++; s = 0;
                BFS(i, j);
                if(s > maxS) maxS = s;
            }
        }
    }

    cout << num << endl;
    cout << maxS;
}

int main(){

    input();
    solve();
}
