#include<bits/stdc++.h>
#define MAX 3001

using namespace std;

int n, k; //INPUT
int kk;
int c[MAX], a[MAX]; // INPUT - vecto of amount of goods and energy
int g, e; // g - amount of goods, e - amount of energy
int x[MAX]; // luu hanh trinh;
int ans; // max of amount of goods;
int cmax;

void input(){
    cin >> n >> k;
    kk = k;
    cmax = 0;
    for(int i = 1; i<=n; i++) {
            cin >> c[i];
            if(cmax < c[i]) cmax = c[i];
    }
    for(int i = 1; i<=n; i++) cin >> a[i];
}

void init(){
    g = c[1];
    e = a[1];
    x[1] = 1;
    ans = 0;
}

void solution(){
    if(ans < g){
        ans = g;
    }
}

void TRY(int t)
{
    int pre = x[t-1]; // diem truoc diem t
    for(int i = pre + 1; i<=n; i++){
        int delta = abs(i - x[t-1]);

        if(delta > 0 && delta <= e)
            if((kk >= t && g + c[i] + (kk-t + 1)*cmax > ans) || kk < t){
            x[t] = i; //cout << "x["<< t << "] =  " << i << endl;
            e = a[i];
            g += c[i];
            k--;
            if (x[t] == n) solution();
            else if (k>0) TRY(t+1);

            k++;
            g -= c[i];
            e = a[pre];
        }
    }

}

void solve(){
    init();

    TRY(2); // tim diem dung thu 2 (sau diem 1)

    if (ans > 0) cout << ans;
    else cout << -1;
}

int main(){

    input();
    solve();
}

