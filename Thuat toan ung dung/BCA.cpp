#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

int m; // num of teachers
int n; // num of courses
int h[21]; // h[i] = duration of course i
int a[21][21]; // conflict matrix
int c[21][6]; // course-teacher matrix

int load[6]; // load[i] = total of duration of teacher i
int chooseTeacher[21]; //chooseTeacher[i][t] = teacher t assigned for course i
int f_best; // Thoi luong max cua cac giao vien

void input(){
    cin >> n >> m;

    int i, j;
    for (i = 1; i<=n; i++)
        cin >> h[i];

    for (int i = 1; i<=n; i++){
        cin >> c[i][0]; // c[i][0] = num of teachers who can teach course i
        for (j = 1; j<=c[i][0]; j++)
            cin >> c[i][j];
    }

    for(i = 1; i<=n; i++)
    for (j = 1; j<=n; j++){
        cin >> a[i][j];
    }
}

int check(int k, int t){// Kiem tra xem khoa hoc k co giao duoc cho giao vien t?
    for(int i = 1; i<=k-1; i++)
        if (a[k][i] == 1)
        if (chooseTeacher[i] == t)
        return 0;
    return 1;
}

void solution(){
    int temp = 0;
    if(1){
        for(int i = 1; i<=m; i++){
            if (temp < load[i]) temp = load[i];
        }
        if (temp < f_best) f_best = temp;
    }
}

void TRY(int i){ // Chon giao vien cho khoa hoc i
    int d = c[i][0];
    for (int j = 1; j<=d; j++){
        int t = c[i][j];
        if (check(i, t)){
            chooseTeacher[i] = t;
            load[t] += h[i];

            if (i == n) solution();
            else TRY(i+1);

            load[t] -= h[i];
        }
    }
}

void solve(){
        f_best = 100000;
        for(int i = 1; i<=m; i++) load[i] = 0;

        TRY(1); // Chon giao vien cho khoa hoc 1;

        if(f_best < 100000) cout << f_best;
        else cout << -1;
}

int main(){
    input();
    solve();
//    for(int i = 1; i<=n; i++){
//        for (int j = 0; j<=m; j++)
//            cout << c[i][j] << " ";
//        cout << endl;
//    }

}
