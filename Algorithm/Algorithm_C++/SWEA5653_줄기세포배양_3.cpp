/*
	11:25 - 12:55
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, k;

struct Cell {
	int life;
	int now;
};
Cell map[600][600];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;
		for (int i = 0; i < 600;i++) {
			for (int j = 0; j < 600; j++) {
				map[i][j].life = 0;
				map[i][j].now = 0;
			}
		}
		queue<pair<int, int>> q[11];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				Cell cell;
				cin >> cell.life;
				cell.now = cell.life * 2;
				q[cell.life].push({ i+300,j+300 });
				map[i+300][j+300] = cell;
			}
		}
		while (k--) {
			for (int p = 10; p >= 1; p--) {
				int size = q[p].size();
				for (int i = 0; i < size; i++) {
					int x = q[p].front().first;
					int y = q[p].front().second;
					q[p].pop();
					if (map[x][y].life == map[x][y].now) {
						//È®»ê
						for (int j = 0; j < 4; j++) {
							int nx = x + dx[j];
							int ny = y + dy[j];
							if (map[nx][ny].life == 0) {
								map[nx][ny].life = map[x][y].life;
								map[nx][ny].now = map[x][y].life * 2;
								q[p].push({ nx,ny });
							}
						}
					}
					map[x][y].now--;
					if (map[x][y].now != 0) {
						q[p].push({ x,y });
					}
				}
			}
		}
		int answer = 0;
		for (int i = 10; i >= 1; i--) {
			answer += q[i].size();
		}
		cout << "#" << t << " " << answer << endl;
	}
}