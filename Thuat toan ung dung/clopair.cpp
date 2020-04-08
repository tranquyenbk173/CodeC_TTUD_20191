#include<bits/stdc++.h>
#define MAX 50001
using namespace std;
int n;
int x[MAX], y[MAX];
int a, b;
float mind = FLT_MAX;

float d(int i, int j){
 float xx = pow(x[i]-x[j], 2);
 float yy = pow(y[i]-y[j], 2);
 return sqrt(xx + yy);
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            float temp = d(i, j);
            if(temp < mind){
                mind = temp;
                a = i;
                b = j;
            }
        }
    }

    printf("%d %d %f", a, b, mind);
}
