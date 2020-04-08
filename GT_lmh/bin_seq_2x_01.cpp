#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int n, i, j, x[MAX];

int main(){

    cout << "Nhap n: ";
    cin >> n;

    if(n==0){
        cout << "Day rong!";
        return 0;
    }

    for(i = 0; i<n; i++){
        x[i] = 0;
    }

    while(i>=0){
        int dem=0;
        for(j = 0; j<n; j++)
        {
            if(x[j]==0 && x[j+1] == 1)dem++;
        }
        if(dem == 2){
            for(int j = 0; j<n; j++) cout << x[j] << " ";
            cout << endl;
        }

        j = n-1;
        while(x[j] == 1 && j>=0) j--;
        i = j;
        if(j>=0){
            x[j] = 1;
            for(int j = i+1; j<n; j++) x[j] = 0;
        }

    }

    return 0;
}
