/*
	17:15 - 18:45
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, k, answer=-1;
int map[13][13];
deque<int> v[13][13];
int chess[11][3];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		//행, 열, 이동번호, 우좌상하
		cin >> chess[i][0] >> chess[i][1] >> chess[i][2];
		v[chess[i][0]][chess[i][1]].push_back(i);
 	}
	int t = 0;
	bool isFin = false;
	while (t<=1000) {
		//모든 턴 돌기
		for (int i = 1; i <= k; i++) {
			int x = chess[i][0];
			int y = chess[i][1];
			int dir = chess[i][2];
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n || map[nx][ny] == 2) {
				if (dir == 1 || dir == 3) {
					dir += 1;
				}
				else {
					dir -= 1;
				}
				nx = x + dx[dir];
				ny = y + dy[dir];
				if (map[nx][ny] != 2 && nx>0 && ny>0 && nx<=n && ny<=n) {
					if (map[nx][ny] == 0) {
						int sz = v[x][y].size();
						deque<int> tmpv;
						for (int j = 0; j < sz; j++) {
							int idx = v[x][y].back();
							tmpv.push_back(idx);
							v[x][y].pop_back();
							chess[idx][0] = nx;
							chess[idx][1] = ny;
							if (i == idx) {
								break;
							}
						}
						while (!tmpv.empty()) {
							v[nx][ny].push_back(tmpv.back());
							tmpv.pop_back();
						}
					}
					else if (map[nx][ny] == 1) {
						int sz = v[x][y].size();
						for (int j = 0; j < sz; j++) {
							int idx = v[x][y].back();

							v[nx][ny].push_back(idx);
							v[x][y].pop_back();
							chess[idx][0] = nx;
							chess[idx][1] = ny;
							if (i == idx) {
								break;
							}
						}
					}
				}
				else {
					nx = x;
					ny = y;
				}
				chess[i][0] = nx;
				chess[i][1] = ny;
				chess[i][2] = dir;
			}
			else if (map[nx][ny] == 0) {
				int sz = v[x][y].size();
				deque<int> tmpv;
				for (int j = 0; j < sz; j++) {
					int idx = v[x][y].back();
					tmpv.push_back(idx);
					v[x][y].pop_back();
					chess[idx][0] = nx;
					chess[idx][1] = ny;
					if (i == idx) {
						break;
					}
				}
				while (!tmpv.empty()) {
					v[nx][ny].push_back(tmpv.back());
					tmpv.pop_back();
				}
			}
			else if (map[nx][ny] == 1) {
				int sz = v[x][y].size();
				for (int j = 0; j < sz; j++) {
					int idx = v[x][y].back();
					
					v[nx][ny].push_back(idx);
					v[x][y].pop_back();
					chess[idx][0] = nx;
					chess[idx][1] = ny;
					if (i == idx) {
						break;
					}
				}
			}
			if (v[nx][ny].size() >= 4) {
				isFin = true;
				break;
			}
		}
		
		if (isFin) {
			answer = t+1;
			break;
		}
		t++;
	}
	cout << answer;
}