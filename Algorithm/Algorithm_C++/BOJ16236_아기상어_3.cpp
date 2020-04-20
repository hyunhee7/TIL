/*
	13:20 - 14:50
*/
#define MAX 987654321
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int map[20][20];
bool visited[20][20];
int n;
int now_x, now_y;
int level, status;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int bfs() {
	queue<pair<int, int>> q;
	visited[now_x][now_y] = true;
	q.push({ now_x, now_y });
	int time = 1;
	int dis = MAX;
	int dis_x = MAX;
	int dis_y = MAX;
	while (!q.empty()) {
		int qsize = q.size();
		for (int s = 0; s < qsize; s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
				//물고기 크기 체크
				int fish_level = map[nx][ny];
				//cout << fish_level << endl;

				//1. 물고기가 큰 경우
				if (fish_level > level) {
					visited[nx][ny] = true;
				}
				//2. 같은 경우 or 아무것도 없는 경우
				else if (fish_level == 0 || fish_level == level) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				//3. 작은 경우(먹기, 끝내기)
				else {
					if (nx < dis_x) {
						dis = time;
						dis_x = nx;
						dis_y = ny;
					}
					else if (nx == dis_x) {
						if (ny < dis_y) {
							dis = time;
							dis_x = nx;
							dis_y = ny;

						}
					}
				}
			}
		}
		if (dis < MAX) {
			now_x = dis_x;
			now_y = dis_y;
			map[dis_x][dis_y] = 0;
			status++;
			if (status == level) {
				status = 0;
				level++;
			}
			return dis;
		}
		time++;
	}
	return 0;
}
int main() {

	cin >> n;
	level = 2; //물고기 크기
	status = 0; // 경험치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				now_x = i;
				now_y = j;
				map[i][j] = 0;
			}
		}
	}
	int time = 0;
	bool isOK = true;
	while (isOK) {
		memset(visited, 0, sizeof(visited));
		int val = bfs();
		if (val == 0) isOK = false;
		else time += val;
	}
	cout << time << endl;
}