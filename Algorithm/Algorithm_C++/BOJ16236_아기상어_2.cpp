/*
	14:25-15:55
*/
#include <iostream>
#include <queue>
using namespace std;
int map[21][21];
int visited[21][21];
int n;
int now_x, now_y;
int status = 0, level = 2;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int answer = 0;
int min_x, min_y,min_dis;
void bfs() {
	queue<pair<int, int>> q;
	q.push({ now_x,now_y });
	visited[now_x][now_y] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		//cout << x << " " << y << endl;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] > level || visited[nx][ny] != -1 || nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			
			visited[nx][ny] = visited[x][y] + 1;
			if (map[nx][ny] > 0 && map[nx][ny] < level) {
				if (visited[nx][ny] < min_dis) {
					min_dis = visited[nx][ny];
					min_x = nx;
					min_y = ny;
				}
				else if (visited[nx][ny] == min_dis) {
					if (nx == min_x) {
						if (ny < min_y) {
							min_y = ny;
							min_x = nx;
						}
					}
					else if (nx < min_x) {
						min_x = nx;
						min_y = ny;
					}
				}
				//cout << "min: " << min_x << " " << min_y << " "<<min_dis<< endl;
			}
			//cout << "in: "<<nx << " " << ny << endl;
			q.push({ nx,ny });
		}
	}
}
int main() {
	cin >> n;
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

	while (true) {
		//√ ±‚»≠
		min_x = 21; min_y = 21; min_dis = 21;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = -1;
			}
		}
		//cout << "now_x:" << now_x << " " << "now_y:" << now_y << endl;
		bfs();
		//cout << "-------" << endl;
		if (min_x != 21 && min_y != 21) {
			//cout << min_x<<" "<<min_y << endl;
			answer += visited[min_x][min_y];
			status++;
			if (status == level) {
				level++;
				status = 0;
			}
			now_x = min_x;
			now_y = min_y;
			map[now_x][now_y] = 0;
		}
		else
			break;
	}
	cout << answer;
}