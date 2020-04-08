#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

struct node{
    int val;
    node* next = NULL;
};
int n, m, num;
int u, v;
int visited[MAX+1];

struct node* List[MAX + 1];

input(){
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        cin >> u >> v;

        node *p = new node();
        p->val = v;

        if(List[u] == NULL){
            List[u] = p;
        }else{
            p->next = List[u];
            List[u] = p;
        }

        node *q = new node();
        q->val = u;

        if(List[v] == NULL){
            List[v] = q;
        }else{
            q->next = List[v];
            List[v] = q;
        }
    }
}

void DFS(int u){
    visited[u] = 1;
    node *p = List[u];
    while(p != NULL){
        int v = p->val;
        if(visited[v] == 0){
            DFS(v);
        }
        p = p->next;
    }
}

void solve(){
    for(int i = 1; i<=n; i++) visited[i] = 0;

    num = 0;
    for(int u = 1; u<=n; u++){
        if(visited[u] == 0){
            num++;
            DFS(u);
        }
    }

    cout<< num;
}

int main(){
    input();
    solve();
}
