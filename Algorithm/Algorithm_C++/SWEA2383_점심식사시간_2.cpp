/*
	12:00 - 13:30
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <cstring>
using namespace std;
int n;
int map[11][11];
vector<pair<int, int>> list;
vector<pair<int, int>> stair;
int pnum, answer;
bool team[10];

void dfs(int index) {
	if (index == pnum) {
		//길이 apq, bpq에 넣기;
		int d[11];
		queue<int> q[2];
		for (int i = 0; i < pnum; i++) {
			d[i] = abs(stair[team[i]].first - list[i].first) + abs(stair[team[i]].second - list[i].second);
		}
		int fin = 0;
		int time = 0;
		while (true) {
			if (time >= answer) break;
			if (fin == pnum) {
				if (time < answer) answer = time;
				break;
			}
			for (int i = 0; i < 2; i++) {
				int qsize = q[i].size();
				for (int j = 0; j < qsize; j++) {
					int val = q[i].front() - 1;
					q[i].pop();
					if (val == 0) {
						fin++;
					}
					else {
						q[i].push(val);
					}
				}

			}
			for (int i = 0; i < pnum; i++) {
				if (time == d[i]) {
					if (q[team[i]].size() < 3) {
						q[team[i]].push(map[stair[team[i]].first][stair[team[i]].second]);
					}
					else {
						q[team[i]].push(map[stair[team[i]].first][stair[team[i]].second] + q[team[i]].front());
					}

				}
			}
			time++;
		}
		return;
	}
	team[index] = 0;
	dfs(index + 1);
	team[index] = 1;
	dfs(index + 1);
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		answer = 987654321;
		list.clear();
		stair.clear();
		memset(team, 0, sizeof(int));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					list.push_back({ i,j });
				}
				else if (map[i][j] > 1) {
					stair.push_back({ i,j });
				}
			}
		}
		pnum = list.size();
		dfs(0);
		cout << "#" << t << " " << answer << endl;
	}
}