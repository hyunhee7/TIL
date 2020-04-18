/*
	14:15 - 15:45
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, k;
int answer = 0;
vector<int> map[10][10];
int added[10][10];
int now[10][10];
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int dy[] = { 0,0,1,-1,-1,1,1,-1 };
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			now[i][j] = 5;
			cin >> added[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		map[x-1][y-1].push_back(age);
	}
	for (int time = 0; time < k; time++) {
		//봄, 여름
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				queue<int> nut;
				//나이순 정렬
				if (map[i][j].size() > 1) {
					sort(map[i][j].begin(), map[i][j].end());
				}
				//나이순 양분먹기
				for (int p = 0; p < map[i][j].size(); p++) {
					bool fin = false;
					if(fin){
						nut.push(map[i][j][p] / 2);
						map[i][j][p] = 0;
					}
					if (now[i][j] - map[i][j][p] >= 0) {
						now[i][j] -= map[i][j][p];
						map[i][j][p]++;
					}
					else {
						fin = true;
						nut.push(map[i][j][p] / 2);
						map[i][j][p] = 0;
					}
				}
				for (int p = map[i][j].size() - 1; p >= 0; p--) {
					if (map[i][j][p] <= 0) {
						map[i][j].pop_back();
					}
					else {
						break;
					}
				}
				while (!nut.empty()) {
					now[i][j] += nut.front();
					nut.pop();
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int p = 0; p < map[i][j].size(); p++) {
					if (map[i][j][p] % 5 == 0) {
						for (int q = 0; q < 8; q++) {
							int nx = i + dx[q];
							int ny = j + dy[q];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
							map[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				now[i][j] += added[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += map[i][j].size();
		}
	}
	cout << answer;
}