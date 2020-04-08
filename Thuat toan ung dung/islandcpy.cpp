#include <iostream>
using namespace std;

#define MAX 2000
int n, m;
char a[MAX][MAX];

int visited[MAX][MAX];
int sum; int max_area; int area;
int xMove[4] = { 0, 0, -1, 1 };
int yMove[4] = { -1, 1, 0, 0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == 0 && a[x][y] == '1';
}

void DFS(int x, int y) {
	visited[x][y] = 1;

	area++;
	for (int i = 0; i < 4; i++) {
		int next_x = x + xMove[i];
		int next_y = y + yMove[i];
		if (check(next_x, next_y)) {
			DFS(next_x, next_y);
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
	sum = 0; max_area = 0; area = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (check(x, y)) {
				area = 0;
				DFS(x, y);
				sum++;
				if (max_area < area) {
					max_area = area;
				}
			}
		}
	}

	cout << sum << endl;
	cout << max_area << endl;
}

int main()
{
	input();
	solve();
}
