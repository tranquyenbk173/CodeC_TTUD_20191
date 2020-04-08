#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 5;
vector<int> v[NMAX];
bool flag[NMAX], del[NMAX];
int low[NMAX], num[NMAX];
int t = 0;
int res = 0;
int s[NMAX], top = 0;

void push(int u) {
	s[top] = u;
	top++;
}

int pop() {
	top--;
	return s[top];
}

void visit(int u) {
	t++;
	num[u] = t;
	low[u] = t;
	flag[u] = true;
	push(u);
	int n = v[u].size();
	
	for (int i = 0; i < n; i++) {
		int x = v[u][i];
		if (!del[x]) {
			if (flag[x]) {
				low[u] = min(low[u], num[x]);
			} else {
				visit(x);
				low[u] = min(low[u], low[x]);
			}
		}	
	}
	
	if (low[u] == num[u]) {
		res++;
		while (true) {
			int x = pop();
			del[x] = true;
			if (x == u) {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		v[t1].push_back(t2);
	}
	
	memset(flag, false, sizeof(flag));
	memset(del, false, sizeof(del));
	for (int i = 1; i <= n; i++) {
		if (!del[i]) {
			visit(i);
		}
	}
	
//	for(int i = 1; i <= n; i++) {
//		cout << low[i] << ' ';
//	}
	
	cout << res;
}
