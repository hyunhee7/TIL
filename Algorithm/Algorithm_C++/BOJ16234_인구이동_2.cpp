/*
	16:10 - 17:40
*/
#include <iostream>
#include <queue>
using namespace std;
int n, l, r;
int map[51][51];
bool visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool bfs(int a, int b) {
	bool isMove = false;
	queue<pair<int, int>> q;
	queue<pair<int, int>> list;
	q.push({ a,b });
	list.push({ a,b });
	visited[a][b] = true;
	int total = map[a][b];
	int num = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!visited[nx][ny]) {
				int val = abs(map[x][y] - map[nx][ny]);
				if (val >= l && val <= r) {
					total += map[nx][ny];
					num += 1;
					visited[nx][ny] = true;
					q.push({ nx,ny });
					list.push({ nx,ny });
				}
			}
		}
	}
	if (num > 1) {
		int val = total / num;
		//cout << total << " " << num << endl;
		while (!list.empty()) {
			map[list.front().first][list.front().second] = val;
			list.pop();
		}
		isMove = true;
	}
	return isMove;
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int res = 0;
	while (res <= 2000) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					bool isMove = bfs(i, j);
					if (isMove) cnt++;
				}
			}
		}

		if (cnt == 0)break;
		else res += 1;
		//cout << "---" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
				//cout << map[i][j] << ' ';
			}
			//cout << endl;
		}
	}
	cout << res;
}