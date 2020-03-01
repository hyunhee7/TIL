#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
int map[101][101];
int visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		//cout << x << ' ' << y << endl;
		q.pop();
		if (x == n && y == m) return;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (map[nx][ny] == 1 && visited[nx][ny]==0) {
				visited[nx][ny] = visited[x][y] + 1;
				//cout << nx <<" "<<ny<<", val:" << visited[nx][ny]<<endl;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			map[i][j+1] = line[j] - '0';
		}
	}
	bfs(1, 1);
	cout << visited[n][m];
}