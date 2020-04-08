#include <bits/stdc++.h>

using namespace std;

const int N = 1<<20; // no

int s[N], t[N], ls[N], lt[N];//no - khai bao o tren static de tranh tran stack (co the, vi khi dat het xuong main thi loi)

int main() {
	ios::sync_with_stdio(false); // giam toc do chay cua chuong trinh

	int n; // de o daay hoac tren vung static deu duoc
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
		lt[t[i]] = max(lt[t[i]], t[i]-s[i]); // cho nay co the gan truc tiep gia tri luon
		ls[s[i]] = max(ls[s[i]], t[i]-s[i]);
	}

	for (int i = 1; i <= (int) 1e6; i++) { // minh nghi chuong trinh sai o cho start va endd
		lt[i] = max(lt[i], lt[i-1]);
		//cout << "here!";
	}

    //cout << "donew!";

	for (int i = (int) 1e6; i >= 1; i--) {
		ls[i] = max(ls[i], ls[i+1]);
	}

	int res = 0;

	for (int i = 1; i <= (int) 1e6; i++) {
		res = max(res, lt[i-1] + ls[i]);
	}

	cout << res << endl;

	return 0;
}
