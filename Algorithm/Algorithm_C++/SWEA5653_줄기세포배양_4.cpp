/*
	12:30 - 14:00
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Cell {
	int life;
	int now;
};
queue<pair<int, int>> q[11];
Cell map[750][750];
int n, m, k, answer;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;
		//초기화
		for (int i = 0; i < 750; i++) {
			for (int j = 0; j < 750; j++) {
				map[i][j].life = 0;
				map[i][j].now = 0;
			}
		}
		answer = 0;
		for (int i = 1; i < 11; i++) {
			while (!q[i].empty()) q[i].pop();
		}

		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = 0; j < m; j++) {
				cin >> tmp;
				map[i + 300][j + 300].life = tmp;
				map[i + 300][j + 300].now = tmp*2;
				q[tmp].push({ i + 300,j + 300 });
			}
		}
		while (k--) {
			if (k < 0) break;
			//1.활성화된 세포 임시 큐에 넣기
			queue<pair<int, int>> v[11];
			for (int i = 10; i >= 1; i--) {
				//크기가 i인 세포
				int qsize = q[i].size();
				for (int j = 0; j < qsize; j++) {
					int x = q[i].front().first;
					int y = q[i].front().second;
					q[i].pop();
					//활성화 세포
					if (map[x][y].now == i) {
						for (int p = 0; p < 4; p++) {
							int nx = x + dx[p];
							int ny = y + dy[p];
							//cout << "nx,ny: " << nx << " " << ny << " " << map[nx][ny].life << endl;
							if (map[nx][ny].life == 0) {
								v[i].push({ nx,ny });
								map[nx][ny].life = i;
								map[nx][ny].now = i * 2;
							}
						}
						
					}
					//생명력 감소
					map[x][y].now--;
					//살아있으면 다시 넣어주기
					if (map[x][y].now > 0) {
						q[i].push({ x,y });
					}
				}
			}
			//2.
			for (int i = 10; i >= 1; i--) {
				if (v[i].empty())continue;
				while (!v[i].empty()) {
					int x = v[i].front().first;
					int y = v[i].front().second;
					v[i].pop();
					q[i].push({ x,y });
				}
			}
		}
		for (int i = 10; i >= 1; i--) {
			answer += q[i].size();
		}
		cout << "#" << t << " " << answer <<"\n";
	}
}