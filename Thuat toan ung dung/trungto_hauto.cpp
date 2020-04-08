#include<bits/stdc++.h>


using namespace std;

char s[100], t[100];
char S[100];
char a[4] = {'+', '-', '*', '/'};
int top;

void init(){
    gets(s);
    top = 0;
}

char pop(){
    char k = S[--top];
}

void push(char c){
    S[top++] = c;
}

void create_hauto(){
    int i,  c, d = 0;
    int l = strlen(s);
    for (i = 0; i<l; i++){
        c = s[i];
        if (c == '(') push(c);
        else if (c == ')'){
            while (c != '('){
                t[d++] = c;
            }
            pop();
        }else if (c >= 0 || c <= 9){
            push(c);
        }else{
            char k = pop();
            if (a[])
        }
    }
}

void solve(){
    create_hauto();
    calculate_hauto();
}

int main(){
    init();
    solve();
}
