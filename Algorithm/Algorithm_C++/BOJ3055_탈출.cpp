/*
	14:10 - 14:40
*/
#include <iostream>
#include <queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int r, c;
int answer = -1;
int map[51][51];
bool visited[51][51];
vector<pair<int, int>> water;
void bfs(int a, int b) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	visited[a][b] = true;
	int time = 1;
	while (!q.empty()) {
		int qsize = q.size();
		int wat = water.size();
		for (int i = 0; i < wat; i++) {
			int x = water[i].first;
			int y = water[i].second;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c)continue;
				if (map[nx][ny] == 0) {
					water.push_back({ nx,ny });
					map[nx][ny] = 1;
					visited[nx][ny] = true;
				}
			}
		}
		/*for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}*/
		for (int p = 0; p < qsize; p++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c)continue;
				if (map[nx][ny] == 100 && !visited[nx][ny]) {
					answer = time;
					return;
				}
				else if (map[nx][ny] == 0 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		time++;
	}
}
int main() {
	cin >> r >> c;
	int start_x = 0;
	int start_y = 0;
	for (int i = 0; i < r; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < c; j++) {
			if (line[j] == 'D') {
				map[i][j] = 100;
			}
			else if (line[j] == 'S') {
				start_x = i;
				start_y = j;
				map[i][j] = 0;
			}
			else if (line[j] == '.') {
				map[i][j] = 0;
			}
			else if(line[j] == '*') {
				map[i][j] = 1;
				water.push_back({ i,j });
			}
			else {
				map[i][j] = -1;
			}
		}
	}
	bfs(start_x, start_y);
	if (answer == -1) {
		cout << "KAKTUS" << endl;
	}
	else cout << answer << endl;
}
