/*
	15:00 - 16:30
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int,int>> virus;
int n, m, vin=0;
int answer = 987654321;
void dfs(int cnt, vector<int> v) {
	if (v.size()==m) {
		//활성화
		//cout << endl;
		int visited[51][51];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = -1;
			}
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < v.size(); i++) {
			q.push({ virus[v[i]].first,virus[v[i]].second });
			visited[virus[v[i]].first][virus[v[i]].second] = 0;
		}
		//퍼뜨리기
		int num = 0;
		int res = 0;
		while (!q.empty()) {
			int qsize = q.size();
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
				if (visited[nx][ny] == -1 && map[nx][ny] != 1) {
					visited[nx][ny] = visited[x][y] + 1;
					if (map[nx][ny] == 0) {
						num++;
					}
					q.push({ nx,ny });
					res = visited[nx][ny];
				}
			}
			if (num == vin) break;
		}
		/*cout << "---------" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << visited[i][j] << ' ';
			}
			cout << endl;
		}*/
		if (num == vin) {
			//cout << num << endl;
			if (vin == 0) res = 0;
			if (res < answer)answer = res;
		}
		return;
	}
	if (cnt >= virus.size()) return;
	dfs(cnt + 1, v);
	v.push_back(cnt);
	dfs(cnt + 1, v);
	v.pop_back();
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				vin++;
			}
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	//
	vector<int> v;
	dfs(0,v);
	if (answer == 987654321) answer = -1;
	cout << answer;
}