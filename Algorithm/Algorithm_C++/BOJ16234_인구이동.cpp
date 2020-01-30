/*
	17:30-19:00
*/
#include <iostream>
#include <queue>
using namespace std;
int n, l, r;
int map[51][51];
bool visited[51][51];
int answer = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool bfs(int a, int b) {
	queue<pair<int,int>> q;
	q.push(make_pair(a, b));
	int total = 0;
	int num = 0;
	bool isVisit = false;
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + 51, false);
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = true;
		total += map[x][y];
		num++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (abs(map[nx][ny] - map[x][y]) >= l && abs(map[nx][ny] - map[x][y]) <= r) {
				q.push(make_pair(nx, ny));
				isVisit = true;
			}
		}
	}
	if (num <= 1) return true;
	if (!isVisit) return true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				map[i][j] = (total / num);
			}
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "---------------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "---------------" << endl;
	return false;
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	bool isFin = false;
	while (!isFin) {
		//인구이동
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				isFin = bfs(i, j);
				if (!isFin) answer++;
			}
		}
	}
	cout << answer;
}