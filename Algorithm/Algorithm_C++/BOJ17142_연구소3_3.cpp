/*
	10:30 - 12:00
*/
#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
int map[50][50];
int vacant;
int answer;
vector<pair<int, int>> virus;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void dfs(int index, int cnt) {
	if (cnt == m) {
		//map복사
		int tmap[50][50];
		bool visited[50][50];
		memset(tmap, 0, sizeof(tmap));
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int>>q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmap[i][j] = map[i][j];
				//cout << tmap[i][j] << ' ';
				if (tmap[i][j] == 3) {
					q.push({ i,j });
					visited[i][j] = true;
				}
			}
			//cout << endl;
		}
		//cout << endl;
		//바이러스 퍼뜨리기
		int v = vacant;
		int time = 1;
		bool isFin = false;
		while (!q.empty()) {
			int qsize = q.size();
			for (int t = 0; t < qsize; t++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					//0
					if (tmap[nx][ny] == 0 && !visited[nx][ny]) {
						v--;
						if (v == 0) {
							isFin = true;
							break;
						}
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
					else if (tmap[nx][ny] == 2 && !visited[nx][ny]) {
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
				if (isFin) break;
			}
			if (isFin) break;
			time++;
		}
		//min값 구하기
		if (isFin && time < answer)answer = time;
		return ;
	}
	if (index >= virus.size())return;
	map[virus[index].first][virus[index].second] = 3;
	dfs(index + 1, cnt + 1);
	map[virus[index].first][virus[index].second] = 2;
	dfs(index + 1, cnt);
}
int main() {
	cin >> n >> m;
	answer = MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				vacant++;
			}
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	//m개 선택하기
	if (vacant == 0) answer = 0;
	else dfs(0, 0);
	if (answer == MAX) answer = -1;
	cout << answer << endl;
}