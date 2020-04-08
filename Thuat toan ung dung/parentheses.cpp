#include<string>
#include<iostream>

using namespace std;

char S[10000]; //Stack
int sz; // size of Stack

//Alg with Stack

void init(){
    sz = 0;
}
void push(char c){
    S[sz] = c;
    sz++;
}
char pop(){
    char c;
    sz--;
    c = S[sz];
    return c;
}

// end of Stack

int check(string s){

    init(); // Khoi tao Stack
    int len = s.size(), i;
    char c, top;

    for(i = 0; i<len; i++){
        c = s[i];
        if (c == '(' || c == '[' || c == '{'){
                push(c);

        }else{
            if (sz == 0) return 0;
            top = pop();
            if (top == '(' && c != ')') return 0;
            if (top == '[' && c != ']') return 0;
            if (top == '{' && c != '}') return 0;
        }
    }
    if ( sz == 0)
        return 1;
    else return 0;
}

int main(){
    int T, test;
    string s;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        cin >> s;
        test = check(s);
        cout << test <<endl;

    }

}
