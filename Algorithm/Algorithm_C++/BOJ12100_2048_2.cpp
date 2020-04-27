/*
	11:45 - 13:15
*/
#include <iostream>
#include <queue>
using namespace std;
int n;
int answer;
void dfs(int dir, int cnt, int (*map)[20]) {
	if (cnt == 5) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > res) res = map[i][j];
			}
		}
		if (res > answer)answer = res;
		return;
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j]<<' ';
		}
		cout << endl;
	}
	cout << endl;*/
	//dir 연산(상하좌우)
	//상
	int tmp = 0;
	int tmap[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmap[i][j] = map[i][j];
		}
	}
	if (dir == 0) {
		for (int col = 0; col < n; col++) {
			queue<int> q;
			for (int row = 0; row < n; row++) {
				if (!tmap[row][col])continue;
				q.push(tmap[row][col]);
			}
			for (int row = 0; row < n; row++) {
				if (q.empty()) {
					tmap[row][col] = 0;
					continue;
				}
				int val = q.front();
				q.pop();
				if (!q.empty() && q.front() == val) {
					q.pop();
					val *= 2;
				}
				tmap[row][col] = val;
			}
		}
	}
	//하
	else if (dir == 1) {
		for (int col = 0; col < n; col++) {
			queue<int> q;
			for (int row = n - 1; row >= 0; row--) {
				if (!tmap[row][col])continue;
				q.push(tmap[row][col]);
			}
			for (int row = n - 1; row >= 0; row--) {
				if (q.empty()) {
					tmap[row][col] = 0;
					continue;
				}
				int val = q.front();
				q.pop();
				if (!q.empty() && q.front() == val) {
					q.pop();
					val *= 2;
				}
				tmap[row][col] = val;
			}
		}
	}
	//좌
	else if (dir == 2) {
		for (int row = 0; row < n; row++) {
			queue<int> q;
			for (int col = 0; col < n; col++) {
				if (!tmap[row][col])continue;
				q.push(tmap[row][col]);
			}
			for (int col = 0; col < n; col++) {
				if (q.empty()) {
					tmap[row][col] = 0;
					continue;
				}
				int val = q.front();
				q.pop();
				if (!q.empty() && q.front() == val) {
					q.pop();
					val *= 2;
				}
				tmap[row][col] = val;
			}
		}

	}
	//우
	else {
		for (int row = 0; row < n; row++) {
			queue<int> q;
			for (int col = n - 1; col >= 0; col--) {
				if (!tmap[row][col])continue;
				q.push(tmap[row][col]);
			}
			for (int col = n - 1; col >= 0; col--) {
				if (q.empty()) {
					tmap[row][col] = 0;
					continue;
				}
				int val = q.front();
				q.pop();
				if (!q.empty() && q.front() == val) {
					q.pop();
					val *= 2;
				}
				tmap[row][col] = val;
			}
		}
	}
	//다음 연산 준비
	for (int i = 0; i < 4; i++) {
		dfs(i, cnt + 1, tmap);
	}
}
int main() {
	cin >> n;
	answer = 0;
	int map[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > answer)answer = map[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		dfs(i, 0, map);
	}
	cout << answer << endl;
}