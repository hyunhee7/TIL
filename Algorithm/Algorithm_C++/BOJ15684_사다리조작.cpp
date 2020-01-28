#include <iostream>
using namespace std;
int n, m, h;
int map[31][11];
bool isFail = false;
bool isFin = false;
int answer = -1;
void dfs(int cnt, int val, int fin) {
	if (isFin) return;
	if (cnt == fin) {
		isFail = false;
		//cout << cnt << endl;
		for (int index = 1; index <= n; index++) {
			int j = index;
			for (int i = 1; i <= h; i++) {
				//cout << "i:" << i << ",j:" << j << endl;
				if (map[i][j] == 1) j += 1;
				else if (j - 1 > 0 && map[i][j - 1] == 1)j -= 1;
			}
			if (index != j) {
				isFail = true;
				break;
			}
		}
		if (!isFail) {
			isFin = true;
			answer = cnt;
		}
		return;
	}

	for (int i = val; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j - 1] == 1 || map[i][j + 1] == 1) continue;
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(cnt + 1, i, fin);
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int i = 0; i <= 3; i++) {
		dfs(0,0,i);
		if (!isFail) break;
	}
	cout << answer;
}