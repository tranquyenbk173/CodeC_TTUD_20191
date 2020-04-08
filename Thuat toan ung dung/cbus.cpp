#include<bits/stdc++.h>
#define MAX 25

using namespace std;

int n, kk; // kk la so khach toi da
int c[MAX][MAX]; // ma tran chi phi
int x[MAX]; // vecto duong di
int visited[MAX]; // Danh dau diem duoc tham toi
int cmin, cost, output, num;

void input(){
    cin >> n >> kk;
    cmin = 10000;
    for (int i =  0; i< n+n+1; i++)
    for (int j = 0; j< n+n+1; j++){
        cin >> c[i][j]; // Nhap ma tran chi phi
        if (i != j && cmin > c[i][j]) cmin = c[i][j]; // Tim cmin - trong so nho nhat tren do thi
    }
}

void init(){
    int i;
    for (i = 0; i<n+1; i++)
        visited[i] = 0; // cac diem don danh dau la chua tham
    for (i = n+1; i<n+n+1; i++)
        visited[i] = 1; // cac diem tra khong duoc tham truoc diem don tuong ung

    cost =  0;// Chi phi hien tai bang 0
    output = 10000;
    num = 0; // So khach dang tren xe
}

void solution(){
    int last = x[n+n];
    if (cost + c[last][0] < output){
        output = cost + c[last][0];
    }
}

void TRY(int k){// Tim loi giai bo phan cap k
    int p = x[k-1];
    int rest = cmin*(n+n-k+1);
    for (int i = 0; i<n+n+1; i++) // Xet cac diem tu 0 den 2*n
    {
        if (visited[i] == 0 && cost + c[p][i] + rest < output) // Neu i chua duoc tham (co the tham)
        {
            if (i < n+1 && num < kk){ //Neu i la diem don va xe van con cho
                visited[i] = 1; visited[i+n] = 0; // Cho phep toi diem tra khach tuong ung
                x[k] = i;
                num ++; // tang so khach tren xe len 1
                cost += c[p][i];

                TRY(k+1); // Tim tiep x[k+1]

                // Hoan lai trang thai truoc do;
                visited[i] = 0; visited[i+n] = 1;
                num--;
                cost -= c[p][i];
            }
            else if (num > 0){ // neu tren xe co khach de tra
                visited[i] = 1;
                x[k] = i;
                num--; // Giam so khach tren xe
                cost += c[p][i];

                if (k == n+n) solution();
                else TRY(k+1);

                //Hoan lai trang thai truoc do:
                visited[i] = 0;
                num++;
                cost -= c[p][i];
            }
        }
    }
}

void solve(){
    visited[0] = 1; // Xuat phat tu diem 0;
    x[0] = 0;

    TRY(1);
}

int main()
{
    input(); // Nhap input
    init(); // Khoi tao cac tham so ban dau
    solve(); // Giai quyet bai toan
    cout << output;
//    cout << "cmin = " << cmin << endl;
//    for (int i = 0; i<2*n+1; i++){
//        cout << x[i] << " ";
//    }
}
