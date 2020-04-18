/*
	11:45 - 13:15
*/
#define MAX 987654321
#include <iostream>
using namespace std;
int map[31][11];
int n, m, h;
int answer;
bool isOK = false;
bool isCorrect() {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][now]) {
				now += 1;
			}
			else if (now > 1 && map[j][now - 1]) {
				now -= 1;
			}
		}
		if (now == i) {
			total++;
		}
		else return false;
	}
	return true;
}
void dfs(int p, int cnt, int res) {
	if (isOK) return;
	if (cnt == res) {
		/*for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= n; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}*/
		if (isOK) return;
		if (isCorrect()) {
			answer = cnt;
			isOK = true;
			return;
		}
		return;
	}
	for (int i = p; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j])continue;
			if ((j - 1 >= 1 && map[i][j - 1]) || (j + 1 <= n && map[i][j + 1]))continue;
			map[i][j] = 1;
			dfs(i, cnt + 1, res);
			if (isOK) return;
			map[i][j] = 0;
		}
	}

}
int main() {
	cin >> n >> m >> h;
	answer = MAX;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	//1일 경우 a+1, b+1 이동

	//1. 확인
	if (!isCorrect()) {
		for (int i = 1; i <= 3; i++) {
			dfs(1, 0, i);
			if (isOK) break;
		}
	}
	else {
		answer = 0;
	}
	if (answer == MAX) answer = -1;
	cout << answer;
}