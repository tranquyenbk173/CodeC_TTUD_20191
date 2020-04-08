#include<bits/stdc++.h>

using namespace std;

int a, b, c, T;
int x, y, z; // z la so buoc it nhat
int qx[100000], qy[100000], head, tail;
int qz[1000][1000];

//Cac thao tac voi queue
void push(int xx, int yy){
    if (xx == 0 && yy == 0) return;
    if (qz[xx][yy] == 0)
    {
        qx[++head] = xx;
        qy[head] = yy;
        qz[xx][yy] = qz[x][y]+1;
    }
}

void pop(){
    x = qx[tail];
    y = qy[tail++];
}

// end Queue

void init(){
    tail = head = 0;
    for (int i = 0; i<1000; i++)
        for (int j = 0; j<1000; j++)
        qz[i][j] = 0;
    qx[0] = qy[0] = 0;
    z = 1000;
}

void solution(){
    if (x == 0 && y == 0) return;
    if (z > qz[x][y])
        z = qz[x][y];
}

void check(){
    init(); // Khoi tao cac gia tri ban dau

    while(head >= tail){
        pop();
        if (x == c || y == c || x + y == c) solution();
        else{
            if (x > 0)
                push(0, y);
            if (y > 0)
                push(x, 0);
            if (x < a)
                push(a, y);
            if (y < b)
                push(x, b);
            if (x + y < b)
                push(0, x+y);
            if (x + y >=b)
                push(x+y-b, b);
            if (x + y < a)
                push(x+y, 0);
            if (x + y >= a)
                push(a, x+y-a);
        }
    }
}

int main(){

    cin >> T;

    for (int i = 0; i<T; i++){
        cin >> a >> b >> c;
        check();
        if ( z!= 1000) cout << z << endl;
        else cout << -1;

//        for (int i = 0; i<=head; i++)
//            cout << qx[i] << " ";
//        cout << endl;
//        for (int i = 0; i<=head; i++)
//            cout << qy[i] << " ";
    }
}
