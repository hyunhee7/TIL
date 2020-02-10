/*
	13:10 - 14:40
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
vector<pair<int, int>> person;
vector<pair<int, int>> stair;
int team[10];
int answer = 987654321;

int ps;
int calc() {
	int time = 0;
	int pass = 0;
	int d[11];
	queue<int> q[2];
	for (int i = 0; i < ps; i++) {
		d[i] = abs(stair[team[i]].first - person[i].first) + abs(stair[team[i]].second - person[i].second);
	}
	while (true) {
		if (time >= answer) return time;
		if (pass == ps) return time;
		
		//계단
		for (int i = 0; i < 2; i++) {
			int sz = q[i].size();
			for (int j = 0; j < sz; j++) {
				int val = q[i].front();
				q[i].pop();
				val -= 1;
				if (val == 0) {
					pass++;
				}
				else {
					q[i].push(val);
				}
			}
		}
		//입구도착
		for (int i = 0; i < ps; i++) {
			if (time == d[i]) {
				if (q[team[i]].size() < 3) {
					q[team[i]].push(map[stair[team[i]].first][stair[team[i]].second]);
				}
				else {
					q[team[i]].push(map[stair[team[i]].first][stair[team[i]].second]+q[team[i]].front());
				}
			}
		}
		time++;
	}
}
void dfs(int cnt) {
	if (cnt == ps) {
		int res = calc();
		//cout << res<< endl;
		if (res < answer) answer = res;
		return;
	}
	team[cnt] = 0;
	dfs(cnt+1);
	team[cnt] = 1;
	dfs(cnt+1);
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		person.clear();
		stair.clear();
		memset(team, 0, sizeof(int));
		/*for (int i = 0; i < 11; i++) {
			memset(map[i], 0, sizeof(int) + 11);
		}*/
		answer = 987654321;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					person.push_back(make_pair(i, j));
				}
				else if (map[i][j] > 1) {
					stair.push_back(make_pair(i, j));
				}
			}
		}
		ps = person.size();
		dfs(0);
		cout << "#" << t << " " << answer << endl;
	}
}