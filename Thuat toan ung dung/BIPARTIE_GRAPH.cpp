#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
struct node{
    int val;
    node* next = NULL;
};
struct node* List[MAX + 1];
int n, m;
int u[MAX + 1], v[MAX + 1];
int color[MAX + 1];
int Q[MAX + 1], head, tail;

void init(){
    head = tail = 0;
}

void push(int a){
    Q[head++] = a;
}

int pop(){
    return Q[tail++];
}

void input(){
    int a, b;
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        cin >> u[i] >> v[i];

        a = u[i]; b = v[i];
        node *p = new node();
        p->val = b;

        if(List[a] == NULL){
            List[a] = p;
        }else{
            p->next = List[a];
            List[a] = p;
        }

        node *q = new node();
        q->val = a;

        if(List[b] == NULL){
            List[b] = q;
        }else{
            q->next = List[b];
            List[b] = q;
        }
    }
}

void BFS(int u, int c){

    node *p = List[u];
    while(p != NULL){
        int v = p->val;
        if(color[v] == 0){
            push(v);
            color[v] = -c;
        }
        p = p->next;
    }

    if(head >= tail){
        int vv = pop();
        BFS(vv, color[vv]);
    }
}

int check(){
    for(int i = 1; i<=m; i++){
        if(color[u[i]] * color[v[i]] == 1) return 0;
    }
    return 1;
}

void solve(){
    init();

    for(int i = 1; i<=n; i++){
        color[i] = 0;
    }

    for(int u = 1; u<=n; u++){
        if(color[u] == 0){
            color[u] = 1;
            BFS(u, 1);
        }
    }

    cout << check();
}

int main(){
    input();
    solve();
}
