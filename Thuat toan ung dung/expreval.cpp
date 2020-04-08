#include<bits/stdc++.h>
#define M 200000

using namespace std;
int n, a[M], b[M];

char S[M]; // Stack, top la vi tri tren phan tu dau stack
int top;
char postfix[M]; // mang chua bieu thuc trung to va hau to
int k = 0; // k la con tro tren postfix

// Cac thao tac voi stack:
void init(){
    top = 0;
}
void push(char a){
    S[top++] = a;
}
char pop(){
    char a = S[top - 1];
    top --;
    return a;
}
//end of Stack

void input(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 1; i<n; i++) cin >> b[i];
    //cout << "init done";
}

int uutien(char x){
    if(x == '-' || x == '+') return 1;
    else if (x == '*') return 2;
}

void solve(){
    top = 0;
    char t, t1;


    // chuyen trung to thanh hau to:
    k = 0;
    postfix[k++] = char(a[0]+ 48);

    for(int i = 1; i<n; i++){
        // xet toan tu b[i]:
        if(top <= 0){// khi Stack rong, dua toan tu vao ngan xep;
            if(b[i] == 0) push('-');
            else if (b[i] == 1) push('+');
            else if (b[i] == 2) push('*');
        } else{// khi Stack khong rong:

            t = S[top-1]; // xet t la phan tu dau ngan xep;

            if(b[i] == 0) t1 = '-'; // t1 la toan tu dang xet
            else if(b[i] == 1) t1 = '+';
            else if(b[i] == 2) t1 = '*';

            while(uutien(t1) <= uutien(t) && top > 0){
                postfix[k++] = pop();
                t = S[top-1];
            }

            push(t1);
        }

        // xet toan hang a[i]:
        postfix[k++] = char(a[i] + 48);

        cout<< "ket qua thu " << i << ": " << S << endl << postfix << endl;
    }

    while(top > 0){
        postfix[k] = pop();
        k++;
    }

    // tinh bieu thuc hau to:
    init();
    for(int i = 0; i<k; i++){
        char t = postfix[i];
        if(t != '-' && t != '+' && t != '*')
            push(postfix[i]);
        else{
            int p1, p2;
            p2 = int(pop()) - 48;
            p1 = int(pop()) - 48;

            if(t == '-') p1 = p1 - p2;
            else if (t == '+') p1 = p1+p2;
            else if(t == '*') p1 = p1*p2;

            char p = p1 + 48;
        }
    }
    int ans = pop()
}

int main(){
    input();
    solve();
}
