/*
	11:55 - 13:25
*/
#define MAX 987654321
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int answer;
int map[11][11];
int n;
vector<pair<int, int>> person;
vector<pair<int, int>> stair;
int pnum;
int team[11];//team소속, 거리
int d[11][2];
queue<int> A;
queue<int> B;
void dfs(int index) {
	if (index == pnum) {
		/*for (int i = 0; i < pnum; i++) {
			cout << team[i] << ' ';
		}
		cout << endl;
		for (int i = 0; i < pnum; i++) {
			cout << d[i][0] << ' ';
		}cout << endl;
		for (int i = 0; i < pnum; i++) {
			cout << d[i][1] << ' ';
		}cout << endl;*/
		while (!A.empty()) {
			A.pop();
		}
		while (!B.empty()) {
			B.pop();
		}
		//큐에 넣기
		for (int i = 0; i < pnum; i++) {
			if (!team[i]) {
				A.push(d[i][0]);
			}
			else {
				B.push(d[i][1]);
			}
		}
		//시간 흐름
		int time = 0;
		queue<int> stairA;
		queue<int> stairB;
		while (true) {
			if (stairA.empty() && stairB.empty() && A.empty() && B.empty()) break;
			//계단 내려가기
			int Asize = stairA.size();
			int Bsize = stairB.size();
			for (int i = 0; i < Asize; i++) {
				int val = stairA.front() - 1;
				stairA.pop();
				if (val > 0)stairA.push(val);
			}
			for (int i = 0; i < Bsize; i++) {
				int val = stairB.front() - 1;
				stairB.pop();
				if (val > 0)stairB.push(val);
			}

			//계단 입구 도착
			int AAsize = A.size();
			int BBsize = B.size();
			for (int p = 0; p < AAsize; p++) {
				int v = A.front();
				A.pop();
				if (v == 0) {
					if (stairA.size() >= 3) {
						stairA.push(map[stair[0].first][stair[0].second] + stairA.front());
					}
					else stairA.push(map[stair[0].first][stair[0].second]);
				}
				else {
					A.push(v - 1);
				}
			}
			for (int p = 0; p < BBsize; p++) {
				int v = B.front();
				B.pop();
				if (v == 0) {
					if (stairB.size() >= 3) {
						stairB.push(map[stair[1].first][stair[1].second] + stairB.front());
					}
					else stairB.push(map[stair[1].first][stair[1].second]);
				}
				else {
					B.push(v - 1);
				}
			}
			time++;
			//cout << A.size() << " " << B.size() << " " << stairA.size() << " " << stairB.size() << endl;
			
		}
		if (time < answer)answer = time;
		//cout << "------" << endl;
		return;
	}
	d[index][1] = abs(stair[1].first - person[index].first) + abs(stair[1].second - person[index].second);
	d[index][0] = abs(stair[0].first - person[index].first) + abs(stair[0].second - person[index].second);
	team[index] = 1;
	dfs(index + 1);
	team[index] = 0;
	dfs(index + 1);
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		answer = MAX;
		memset(map, 0, sizeof(map));
		person.clear();
		stair.clear();
		memset(team, 0, sizeof(team));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					person.push_back({ i,j });
				}
				else if (map[i][j] > 1) {
					stair.push_back({ i,j });
				}
			}
		}
		pnum = person.size();
		dfs(0);
		cout << "#" << t << " " << answer << endl;
	}
}