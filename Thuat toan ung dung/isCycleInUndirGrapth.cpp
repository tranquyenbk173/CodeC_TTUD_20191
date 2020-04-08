#include<bits/stdc++.h>
#define MAX 30
using namespace std;
int N, M, T, u, v;
vector<int> adj[MAX]; // danh sach dinh ke cua adj[i]

void input(){
    T = 3;
    N = 2; M = 2;
    adj[0].push_back(1);
    adj[0].push_back(

                     )

    queue q;
    int a = q.isEmpty()
}

bool isCyclic(vector<int> adj[], int V)
{
    int visited[V];
    for(int i = 0; i<V; i++){
        visited[i] = 0;
    }
    queue<int> q;
    int num = 0; // so thanh phan lien thong
    for(int i= 0; i<V; i++){
        if(visited[i] == 0){
            num++;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int j = 0; j<adj[u].size(); j++){
                    int v= adj[u][j];
                    if(visited[v] == 0){
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
        }
    }

    int numE = 0; // dem so canh trong do thi
    for(int i = 0; i<V; i++){
        numE  += adj[i].size();
    }
    numE /=2;
    if(numE + num == V) return false;
    else return true;
}

int main(){
    input();
    solve();
}
