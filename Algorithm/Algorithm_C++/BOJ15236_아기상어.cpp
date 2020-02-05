/*
	11:30-13:00
*/
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int n, m, answer=0;
int shark_x, shark_y, level = 2, status = 0;
int map[21][21];
int visited[21][21];
int fish_num = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int min_dist = 401, min_x = 21, min_y = 21;
void bfs() {
	queue<pair<int, int>> q;
	visited[shark_x][shark_y] = 0;
	q.push(make_pair(shark_x, shark_y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		//cout << x << " " << y << endl;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (visited[nx][ny] != -1 || map[nx][ny] > level)continue;
			visited[nx][ny] = visited[x][y] + 1;
			//if (visited[nx][ny]==0) {
			if (map[nx][ny] < level && map[nx][ny] > 0) {
				if (min_dist > visited[nx][ny]) {
					min_x = nx;
					min_y = ny;
					min_dist = visited[nx][ny];
				}
				else if (min_dist == visited[nx][ny]) {
					if (min_x == nx) {
						if (min_y > ny) {
							min_x = nx;
							min_y = ny;
						}
					}
					else if (min_x > nx) {
						min_x = nx;
						min_y = ny;
					}
				}
			}
			//}
			q.push(make_pair(nx, ny));
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_x = i;
				shark_y = j;
				map[i][j] = 0;
			}
		}
	}
	while (true) {
		for (int i = 0; i < n; i++) {
			fill(visited[i], visited[i] + n, -1);
		}
		min_dist = 401;
		min_x = 21, min_y = 21;
		//물고기먹기
		bfs();
		//레벨
		if (min_x != 21 && min_y != 21) {
			answer += visited[min_x][min_y];
			status++;
			
			if (status >= level) {
				status = 0;
				level += 1;
			}
			shark_x = min_x;
			shark_y = min_y;
			map[shark_x][shark_y] = 0;
		}
		else
			break;

	}
	cout << answer << endl;
}