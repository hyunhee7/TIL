/*
	14:50 - 16:20
*/
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[11][11];
bool visited[11][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs(int a, int b, int val) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	map[a][b] = val;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!visited[nx][ny] && map[nx][ny]==1) {
				visited[nx][ny] = true;
				map[nx][ny] = val;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int val = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				bfs(i, j, val);
				val++;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int start = -1, end = -1;
			int k = 0;
			if (map[i][j] > 0) {

			}
		}
	}
}