#include<bits/stdc++.h>

using namespace std;
const int M = 1<<20;
int n;
int t[M], s[M]; // (nam trong khoang 10^6 thi sao nhi???)okkkkk
int ans, endd;
int b[M], e[M]; // b[i], e[i]: khoang tg cua chu ki lon nhat bat dau sau hoac tai i
                                //hoac ket thuc truoc hoac tai i

void input(){

}

void solve(){

    //ios::sync_with_stdio(false);
    /*
        *Dung quy hoach dong tinh b[i], e[i]. Sau do duyet i tu 1 den n de tim max(e[i], b[i+1])
    */
    //khoi tao:

}

int main(){
    std::ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> s[i] >> t[i];
        cout<< "yo";
    }

    endd = (int) 10e6; // chi la mot cach gan ngan gon hon 1000000
    for(int i = 1; i<=endd; i++){
        b[i] = e[i] = 0;
    }


    for(int i = 1; i<=n; i++){
        b[s[i]] = e[t[i]] = t[i] - s[i];
    }
    //quy hoach dong:
    for(int i = 1; i<=endd; i++){
        if(e[i] < e[i-1]) e[i] = e[i-1];
    }
    for(int i = endd-1; i>=1; i--){
        if(b[i] < b[i+1]) b[i] = b[i+1];
    }

    ans = 0;
    for(int i = 1; i<=endd-1; i++){
        if(ans < e[i] + b[i+1])
            ans = e[i] + b[i+1];
    }

    cout << ans;
}
