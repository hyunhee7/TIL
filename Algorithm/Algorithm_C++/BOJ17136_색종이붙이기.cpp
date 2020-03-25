#include <iostream>
#include <algorithm>
using namespace std;
int map[10][10];
int answer = 987654321;
int paper[6] = { 0,5,5,5,5,5 };
int cnt;
void dfs(int x, int y) {
	if (y == 10) {
		dfs(x + 1, 0);
		return;
	}
	if (x == 10) {
		answer = min(answer, cnt);
		return;
	}
	if (map[x][y] == 0) {
		dfs(x, y + 1);
		return;
	}
	for (int i = 5; i >= 1; i--) {
		if (paper[i] == 0 || x + i > 10 || y + i > 10)continue;
		bool flag = true;
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				if (map[x + j][y + k] == 0) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (!flag) continue;
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				map[x + j][y + k] = 0;
			}
		}
		paper[i]--;
		cnt++;
		dfs(x, y + i);
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				map[x + j][y + k] = 1;
			}
		}
		paper[i]++;
		cnt--;
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 0);
	if (answer == 987654321) {
		cout << -1 << endl;
	}
	else
		cout << answer << endl;
}