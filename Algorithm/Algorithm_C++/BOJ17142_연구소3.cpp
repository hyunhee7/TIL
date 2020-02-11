/*
	14:30 - 16:00
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n, m, answer = 987654321;
int map[51][51];

int c[11];
int num;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int, int>> virus;
void dfs(int index, int cnt) {
	if (index > virus.size()) return;
	if (cnt == m) {
		int visited[51][51];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = -1;
			}
		}
		int val = 0; //바이러스 퍼진 수
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++) {
			q.push(make_pair(virus[c[i]].first, virus[c[i]].second));
			visited[virus[c[i]].first][virus[c[i]].second] = 0;
			//cout << virus[c[i]].first << " " << virus[c[i]].second << endl;
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] == 1) continue;
				if (visited[nx][ny] < 0 ) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		bool isFin = false;
		int maxval = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					if (visited[i][j] == -1) {
						isFin = true;
						break;
					}
					else {
						maxval = max(visited[i][j], maxval);
					}
				}
			}
		}
		if (!isFin) answer = min(answer,maxval);
		return;
	}
	dfs(index + 1, cnt);
	c[cnt] = index;
	dfs(index + 1, cnt + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	dfs(0, 0);
		
	if (answer == 987654321) answer = -1;
	cout << answer;
}