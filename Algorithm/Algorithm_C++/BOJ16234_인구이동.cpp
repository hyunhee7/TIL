/*
	11:00-12:30
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, l, r;
int map[51][51];
bool visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int answer = 0; bool isMove1;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	bool isMove = false;
	vector<pair<int, int>> contry;
	int total = map[a][b];
	int num = 1;
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		contry.push_back(make_pair(x, y));
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (abs(map[x][y] - map[nx][ny]) >= l && abs(map[x][y] - map[nx][ny]) <= r) {
				visited[nx][ny] = true;
				total += map[nx][ny];
				num++;
				isMove = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	if (!isMove) {
		visited[a][b] = false;
		isMove1 = false;
		return;
	}
	else {

		//cout << total << " " << contry.size() << endl;
		for (int i = 0; i < contry.size(); i++) {
			//cout << i << endl;
			map[contry[i].first][contry[i].second] = (total / contry.size());
		}
		isMove1 = true;
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << map[i][j] << ' ';
		//	}
		//	cout << endl;
		//}
		//cout << "--------------" <<endl;
		return;
	}
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
		for (int i = 0; i < n; i++) {
			fill(visited[i], visited[i] + 51, false);
		}
		bool checking = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
					if (isMove1) {
						checking = true;
					}
				}
			}
		}
		if (checking) {
			answer++;
		}
		else {
			isFin = true;
		}
	}
	cout << answer;
}