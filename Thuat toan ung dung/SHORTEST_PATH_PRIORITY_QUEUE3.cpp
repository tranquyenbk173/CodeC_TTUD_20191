#include<bits/stdc++.h>
#include<queue>
#define MAX 1000001
using namespace std;

int n, m, s, t;
typedef pair<int, int> uu;
vector<uu> a[MAX]; // danh sach ke chua cac phan tu (khoang cach, dinh ke)
int d[MAX], pre[MAX];
int heapd[MAX]; // khoang cach cua cac ptu trong heap
int heapu[MAX]; // node cua cac phan tu trong heap
int c; // dem so phan tu trong heap;

/*
- cac thao tac voi minheap
*/
void SWAP(int i, int j){ // doi cho hai phan tu trong Heap theo chi so
    int temp;
    temp = heapd[i];
    heapd[i] = heapd[j];
    heapd[j] = temp;
    temp = heapu[i];
    heapu[i] = heapu[j];
    heapu[j] = temp;
}

void initHeap(){
    c = 1;
    for(int i = 1; i<=n; i++){
        if(i!=s){
            heapd[c] = d[i];
            heapu[c] = i;
            c++;
        }
    }
//
//   for(int i = 1; i<c; i++){
//        cout << heapd[i] << " " << heapu[i] << "\n";
//
//    }
//    cout << "============";
}

void makeHeap(){
    for(int i = 1; i<= c/2; i++){
        int j = i*2;
        if( i*2 +1 < c && heapd[i*2] > heapd[i*2+1]) j = i*2+1;
        if(heapd[i] > heapd[j]){
            SWAP(i, j);
        }
    }
//    for(int i = 1; i<c; i++){
//        cout << heapd[i] << " " << heapu[i] << "\n";
//
//    }
}

int minHeap(){ // tra ve nut co khoang cach d nho nhat va loai bo no
    int res = heapu[1];
    SWAP(1, c);
    c--;
    makeHeap();
    return res; //dinh dau minHeap
}

void upHeap(int i){

    while(i != 1){
        if(heapd[i] < heapd[i/2]){
            SWAP(i, i/2);
            i = i/2;
        }else break;
    }
}

void updateHeap(int u, int du){
    int i;
    for(i = 1; i<c; i++){
        if(heapu[i] == u) break;
    }
    heapd[i] = du;
    upHeap(i);
}

void input(){
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i<=m; i++){
        cin >> u >> v >> w;
        a[u].push_back(uu(w, v));
    }
    cin >> s >> t;

}

void solve(){
    //khoi tao:
    for(int i = 1; i<=n; i++){
        if(i != s){
            d[i] = MAX;
            pre[i] = s;
        }
    }

    d[s] = 0;
    pre[s] = s;

    for(int i = 0; i<a[s].size(); i++){
        int v = a[s][i].second;
        d[v] = a[s][i].first;
    }
    initHeap(); // cout << "c = " << c;
    makeHeap();

    // xu li:

    while(c){
        int v = minHeap();
        for(int i = 0; i<a[v].size(); i++){ // xet danh sach ke cua v
            int u = a[v][i].second;
            if(d[u] > d[v] + a[v][i].first){
                d[u] = d[v] + a[v][i].first;
                updateHeap(u, d[u]);
            }
        }
    }


    cout << d[t];
}

int main(){
    ios::sync_with_stdio(false);
    input();
    solve();
}
