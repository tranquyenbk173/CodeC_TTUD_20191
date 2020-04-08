#include<bits/stdc++.h>
#define MIN -100000
#define MAX 100001
using namespace std;
int n;
int a[MAX];
int s1[MAX], s0[MAX];

void solve(){
    //co so:
    if(a[1] % 2 == 0){
        s0[1] = a[1];
        s1[1] = MIN; // gia tri min bieu thi tong ko ton tai
    }
    else{
        s1[1] = a[1];
        s0[1] = MIN;
    }

    //quy hoach dong:
    for(int i = 2; i<=n; i++){
        if(a[i] % 2 == 0){
            if(s0[i-1] > 0) s0[i] = s0[i-1]  + a[i];
            else s0[i] = a[i];

            if(s1[i-1] > MIN){
                s1[i] = s1[i-1] + a[i];
            }else s1[i] = MIN;
        }else{
            if(s1[i-1] > MIN) s0[i] = s1[i-1] + a[i];
            else s0[i] = MIN;

            if(s0[i-1] > 0){
                s1[i] = s0[i-1] + a[i];
            }else s1[i] = a[i];
        }
    }

    int maxx = MIN;
    for(int i = 1; i<=n; i++){
        if(s0[i] > maxx) maxx = s0[i];
    }

    cout << maxx;
}

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    solve();
}
