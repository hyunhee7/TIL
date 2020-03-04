#include <iostream>
#include <queue>
using namespace std;
int n;
char map[101][101];
bool visited1[101][101];
bool visited2[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs1(int a, int b) {
	queue<pair<int, int>>q;
	visited1[a][b] = true;
	q.push({ a,b });
	char now = map[a][b];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (!visited1[nx][ny] && map[nx][ny] == now) {
				visited1[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
void bfs2(int a, int b) {
	queue<pair<int, int>>q;
	visited1[a][b] = true;
	q.push({ a,b });
	char now = map[a][b];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (!visited2[nx][ny] && (now == 'R' || now == 'G') && (map[nx][ny]=='R' || map[nx][ny]=='G')) {
				visited2[nx][ny] = true;
				q.push({ nx,ny });
			}
			if (!visited2[nx][ny] && now == 'B' && map[nx][ny] == now) {
				visited2[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++) {
			map[i][j] = line[j];
		}
	}
	int val1=0, val2=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited1[i][j]) {
				bfs1(i, j);
				val1++;
			}
			if (!visited2[i][j]) {
				bfs2(i, j);
				val2++;
			}
		}
	}
	cout << val1 << " " << val2;
}