#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;

int a[MAX]; // a[i] = do dai chu trinh cua so i
int s, e, dmax; // dmax la do dai chu trinh max
int d; // d la do dai chu trinh dia phuong

void input(){
    cin >> s >> e;
    for (int i = 0; i<=e; i++){
        a[i] = -1;
    }
}

//void solution(){
//    if (d > dmax) dmax = d;
//}

//void find_max_cycle(int k){ // tim chu trinh lon nhat cua so nguyen k
//    d = 1;
//    while (k > 1){
//        d++;
//        if (k % 2 != 0){
//            k = 3*k + 1;
//        }else{
//            k = k/2;
//        }
//    }
//    solution();
//}

int cycle(int num){
    int k = num;
    int temp = 0;
    while (k > e || a[k] < 0){
        temp ++;
        if (k % 2 == 0)
            k = k/2;
        else k = 3*k+1;
    }
    temp += a[k];
    a[num] =  temp;
    return temp;
}

void solve(){
    a[1] = a[0] = 1;
    dmax = 0;
    for(int i = s; i <=e; i++){
        d =  cycle(i);
        if (d > dmax) dmax = d;
    }
    cout << s <<" "<< e << " " << dmax;
}

int main(){
    cout << "Hello World!";
}
