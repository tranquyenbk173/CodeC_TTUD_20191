#include<bits/stdc++.h>
#include<utility>
#define MAX 205
using namespace std;

int n, m ,k, q;
int x[55], d; // chua cac dinh tren duong di duoc chon
int W1, W2, minW1, minc, minc2;
typedef pair<int, int> ww; // chua (w1, w2) cua 1 canh noi
typedef pair<int, ww> vw; // chua dinh ke va trong so tuong ung
vector<vw> a[MAX]; // danh sach ke (dinh ke, w1, w2)
int choosed[55]; // danh dau dinh da chon hay chua

void input(){
    minc2 = minc = MAX;
    cin >> n >> m >> k >> q;
    int uu, vv, w11, w22;
    pair<int, int> w;
    for(int i = 1; i<=m; i++){
        cin >> uu >> vv >> w11 >> w22;
        w = make_pair(w11, w22);
        a[uu].push_back(vw(vv, w));
        a[vv].push_back(vw(uu, w));
        if(w11 < minc) minc = w11;
        if(w22 < minc2) minc2 = w22;
    }

//    for(int i = 1; i<=n; i++){
//        cout << i << ": ";
//        int sz = a[i].size();
//        for(int j = 0; j<sz; j++){
//            cout << a[i][j].first << " " << a[i][j].second.first << " " << a[i][j].second.second <<endl;
//        }
//    }
}

void solution(){
    //cout << "w1 = "<< W1<< " minW1 = " << minW1;
    if(W1 < minW1 && W2 <=q){
        minW1 =  W1;
//            cout <<endl;
//        for(int i = 1; i<=k+1; i++) cout << x[i] << " ";
//        cout << "---" << minW1;
    }

}

void TRY(int t){
    int u = x[t-1];
    int sz = a[u].size();
    for(int i = 0; i<sz; i++){
        int v = a[u][i].first;
        if(choosed[v] == 0 && (W1 + minc*(k-t+1) < minW1)&& (minc2*(k-t+1) + W2 <=q)){
            //cout << endl << "chon x" << t << "=" << v;
            choosed[v] = 1;
            x[t] = v;// cout << endl << v;
            W1 += a[u][i].second.first;
            W2 += a[u][i].second.second;

            if(t == k){
                // kiem tra xem v co ke voi x[1]?
                int vv = x[1];
                int ss = a[v].size();
                for(int j = 0; j<ss; j++){
                    if(a[v][j].first == vv){
                        if(W1 + a[v][j].second.first < minW1 && W2 + a[v][j].second.second <=q){
                            minW1 = W1 + a[v][j].second.first;
//                            cout <<endl;
//                            for(int ii = 1; ii<=k; ii++) cout << x[ii] << " ";
//                            cout << "--->" << minW1;
                        }
                    }
                }
            }
            if(t == k+1) solution();
            else TRY(t+1);

            choosed[v] = 0;
            W1 -= a[u][i].second.first;
            W2 -= a[u][i].second.second;
        }
    }
}


void solve(){
    W1 =  W2 = 0; // tong trong so w1, w2 tren duong di
    minW1 = 1000000;
    for(int i = 1; i<=n; i++){
        choosed[i] = 0;
    }
    for(int i = 1; i<=n; i++){
        x[1] = i; //cout << endl << "chon x1 = " << i;
        choosed[i] = 1;
        TRY(2);
        choosed[i] = 0;
    }

    cout << minW1;
}

int main(){
    ios::sync_with_stdio(false);
    input();
    solve();
}
