/*
	13:25 - 14:30
*/
#include <iostream>
#include <vector>
using namespace std;
int map[17][17];
int d;
int n, m;
bool p[17];
vector<pair<int, int>> enamy;
int del[3][2];
int answer = 0;
void dfs(int index, int cnt) {
	if (cnt == 3) {
		int delnum = 0;
		int res = 0;
		int finnum = enamy.size();
		while (delnum < finnum) {
			//1. 가장 가까운 거리 적 공격
			int num = 0;
			for (int i = 0; i < m; i++) {
				int min_d = 987654321;
				if (p[i]) {
					for (int j = 0; j < enamy.size(); j++) {
						if (enamy[j].first == -1) continue;
						int d = abs(enamy[j].first - (n + 1)) + abs(enamy[j].second - i);
						if (min_d > d) {
							del[num][0] = enamy[j].first;
							del[num][1] = enamy[j].second;
						}
						else if (min_d == d) {
							if (enamy[j].second > del[num][1]) {
								del[num][0] = enamy[j].first;
								del[num][1] = enamy[j].second;
							}
						}
					}
				}
				num++;
			}
			for (int i = 0; i < 3; i++) {
				if (map[del[i][0]][del[i][1]] == 1) {
					delnum++;
					res++;
					map[del[i][0]][del[i][1]] = 0;
				}
			}
			//2. 이동
			for (int i = 0; i < finnum; i++) {
				map[enamy[i].first][enamy[i].second] = 0;
				enamy[i].first += 1;
				if (enamy[i].first >= n) {
					delnum++;
					enamy[i].first = -1;
				}else
					map[enamy[i].first][enamy[i].second] = 1;
			}
		}
		if (res > answer) answer = res;
		return;
	}
	if (index >= m)return;
	p[index] = true;
	dfs(index + 1, cnt + 1);
	p[index] = false;
	dfs(index + 1, cnt);
}
int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				enamy.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	cout << answer;
}