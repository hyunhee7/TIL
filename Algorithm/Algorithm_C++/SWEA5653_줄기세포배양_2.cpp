#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Cell {
	int power;
	int time;
};
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int n = 0, m = 0, answer=0;
int k = 0;
Cell cell[600][600];
void init() {
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j < 600; j++) {
			cell[i][j].power = 0;
			cell[i][j].time = 0;
		}
	}
	answer = 0;
}
int main() {
	int T = 0, p = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> n >> m >> k;
		queue<pair<int, int>> q[11];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int p = 0;
				cin >> p;
				cell[300 + i][300 + j].power = p;
				cell[300 + i][300 + j].time = 2 * p;
				if (p != 0) {
					q[p].push({ 300 + i,300 + j });
				}
			}
		}
		while (k--) {
			for (int i = 10; i >= 1; i--) {
				int qSize = q[i].size();
				for (int j = 0; j < qSize; j++) {
					int r = q[i].front().first;
					int c = q[i].front().second;
					q[i].pop();
					--cell[r][c].time;
					if (cell[r][c].power > cell[r][c].time) {
						for (int k = 0; k < 4; k++) {
							int y = r + dy[k];
							int x = c + dx[k];
							if (cell[y][x].power == 0) {
								cell[y][x].power = cell[r][c].power;
								cell[y][x].time = 2 * cell[r][c].power;
								q[i].push({ y,x });
							}
						}
					}
					if (cell[r][c].time != 0) {
						q[i].push({ r,c });
					}
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			answer += q[i].size();
		}
		cout << "#" << t << " " << answer;
	}
}