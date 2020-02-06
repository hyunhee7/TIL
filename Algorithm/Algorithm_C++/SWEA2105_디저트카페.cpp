/*
	16:30 - 18:00
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int map[21][21];
bool visited[101];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
int answer = -1;
int startx, starty;
void dfs(int x, int y, int len, int dir, int change) {
	if (change >= 5) return;
	visited[map[x][y]] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == startx && ny == starty && len >= 4 && change >= 3) {
			answer = max(answer, len);
			visited[map[x][y]] = false;
			return;
		}
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[map[nx][ny]]) continue;
		dfs(nx, ny, len + 1, i, i == dir ? change : change + 1);
	}
	visited[map[x][y]] = false;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			fill(map[i], map[i] + n, 0);
		}
		answer = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		//start
		fill(visited, visited + 101, false);
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				startx = i, starty = j;
				dfs(i, j, 1, -1, 0);
			}
		}
		cout << "#"<<t<<" "<<answer<<endl;
	}
}