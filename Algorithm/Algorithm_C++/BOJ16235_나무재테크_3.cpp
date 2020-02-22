/*
	11:30 - 13:00
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
vector<int> map[11][11];
int nut[11][11];
int amap[11][11];
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int dy[] = { 0,0,1,-1,1,-1,-1,1 };
int answer = 0;
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			nut[i][j] = 5;
			cin >> amap[i][j];
		}
	}
	int a, b, age;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> age;
		map[a][b].push_back(age);
	}
	while (k--) {
		//봄, 여름
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int size = map[i][j].size();
				vector<int> save;
				if (size > 1) {
					sort(map[i][j].begin(), map[i][j].end());
				}
				int die = 0;
				for (int p = 0; p < size; p++) {
					int val = map[i][j][p];
					if (nut[i][j] >= val) {
						nut[i][j] -= val;
						save.push_back(val+1);
					}
					else {
						die += (val / 2);
					}
				}
				map[i][j].clear();
				for (int p = 0; p < save.size(); p++) {
					map[i][j].push_back(save[p]);
				}
				nut[i][j] += die;
			}
		}
		//가을
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int p = 0; p < map[i][j].size(); p++) {
					if (map[i][j][p] % 5 == 0) {
						for (int q = 0; q < 8; q++) {
							int nx = i + dx[q];
							int ny = j + dy[q];
							if (nx <= 0 || ny <= 0 || nx > n || ny > n)continue;
							map[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		//겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				nut[i][j] += amap[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].size() > 0) {
				answer += map[i][j].size();
			}
		}
	}
	cout << answer;
}