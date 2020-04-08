#include<bits/stdc++.h>
using namespace std;

int longestArrays(int a[])
{
    int n = 6;
    int s[n], maxx = 1;
    for(int i = 0; i<n; i++) s[i] = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[j] < a[i] && s[i] < s[j] + 1)
                s[i]  = s[j] + 1;
        }

        if(maxx < s[i]) maxx = s[i];
    }

    return maxx;
}

int main(){
    int a[] = {3, 2, 2, 4, 6, 3};
    cout << longestArrays(a);
}
