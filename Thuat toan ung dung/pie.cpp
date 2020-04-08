#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

int T, N, F;
int r[MAX], s[MAX];
int ans[MAX], dem;

void qSort(int a[], int left, int right)
{
    if (left < right) // Neu day co nhieu hon mot phan tu
    {
        int pivot = a[left], s = left, e = right;
        int temp;

        while (s < e){
            while (a[s] <= pivot) s++;
            while (a[e] > pivot) e--;
            if (s < e){
                temp = a[s];
                a[s] = a[e];
                a[e] = temp;
            }
        }
        temp = a[left];
        a[left] = a[e];
        a[e] = temp;

        qSort(a, left, e-1);
        qSort(a, e+1, right);

    }
}

void solve(int N, int F){
    if(N > F){
        qSort(s, 1, N);
        ans[dem++] = s[N-F];
    }else{
        int maxS = s[1];
        if(N>=2){
            for(int i = 2; i<=N; i++)
            if(maxS < s[i]) maxS = s[i];
        }

        int d = 2, v;
        int COUNT = 0;
        while(COUNT < F+1){
            COUNT = 0;
            v = maxS/d;
            for(int i = 1; i<=N; i++){
                COUNT += s[i]/v;
            }
            d++;
        }
        ans[dem++] = v;
    }
}

int main(){
    cin >> T;
    dem = 0;
    for(int i = 1; i<=T; i++){
        cin >> N >> F;
        for(int j = 1; j<=N; j++){
            cin >> r[j];
            s[j] = r[j]*r[j];
        }
        solve(N, F);

    }

    for(int i = 0; i<T; i++) printf("%f\n", ans[i] * atan(1)*4);
}
