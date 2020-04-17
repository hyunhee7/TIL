/*
	15:20 - 16:50
*/
#define MAX 987654321
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n;
int total = 0;
int answer = MAX;
int pnum[11];
int connected[11][11];
bool team[11];
bool isConnected() {
	bool visitedA[11];
	bool visitedB[11];
	memset(visitedA, 0, sizeof(visitedA));
	memset(visitedB, 0, sizeof(visitedB));
	int anum = 0;
	int bnum = 0;
	//A, B팀 갯수 카운트
	for (int i = 1; i <= n; i++) {
		if (team[i])anum++;
		else bnum++;
	}
	bool flag = false;
	queue<int> q;
	int aval = 0;
	//A팀 첫번째 노드 큐에 넣기
	for (int i = 1; i <= n; i++) {
		if (team[i]) {
			aval++;
			visitedA[i] = true;
			q.push(i);
			break;
		}
	}
	//A팀 연결상태 확인
	while (!q.empty()) {
		if (anum == aval) {
			flag = true;
			break;
		}
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (now == i)continue;
			if (connected[now][i] && team[i] && !visitedA[i]) {
				q.push(i);
				visitedA[i] = true;
				aval++;
			}
		}
	}
	//연결 안될 경우 return
	if (!flag) return flag;
	//B팀 첫번째 노드 넣기
	int bval = 0;
	queue<int> qb;
	for (int i = 1; i <= n; i++) {
		if (!team[i]) {
			qb.push(i);
			visitedB[i] = true;
			bval++;
			break;
		}
	}
	//B팀 연결 상태 확인
	while (!qb.empty()) {
		if (bnum == bval) {
			flag = true;
			break;
		}
		int now = qb.front();
		qb.pop();
		for (int i = 1; i <= n; i++) {
			if (now == i)continue;
			if (connected[now][i] && !team[i] && !visitedB[i]) {
				visitedB[i] = true;
				qb.push(i);
				bval++;
			}
		}
	}
	//A, B팀 모두 연결되있을 경우 true
	if (anum == aval && bnum == bval) flag = true;
	else flag = false;
	return flag;
}
void dfs(int index, int res, int cnt) {
	//중복 줄이기 위한 조건문
	if (cnt > n / 2)return;
	if (cnt >= 1) {
		//2.나눠진 팀의 연결 상태 확인
		if (isConnected()) {
			//3.인구 차이 최소값인지 확인
			int bteam = total - res;
			int ans = abs(res - bteam);
			if (answer > ans)answer = ans;
		}
	}
	
	for (int i = index; i <= n; i++) {
		if (team[i])continue;
		team[i] = true;
		dfs(i, res + pnum[i], cnt + 1);
		team[i] = false;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pnum[i];
		total += pnum[i];
	}
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int node;
			cin >> node;
			connected[i][node] = 1;
		}
	}
	//1. 두 팀으로 나누기
	dfs(1, 0, 0);
	if (answer == MAX)answer = -1;
	cout << answer;
	
}