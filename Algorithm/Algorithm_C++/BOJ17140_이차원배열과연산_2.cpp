/*
	11:50 - 13:20
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int r, c, k;
int now_r, now_c;
int map[101][101];
int number[101];
void calc_c() {
	priority_queue<pair<int, int>> pq;
	int maxval = 0;
	for (int i = 1; i <= now_c; i++) {
		for (int j = 1; j <= now_r; j++) {
			number[map[j][i]]++;
		}
		for (int i = 1; i < 101; i++) {
			if (number[i] > 0) {
				pq.push({ number[i],i });
			}
		}
		int j = 1;
		while (!pq.empty()) {
			map[j][i] = pq.top().second;
			map[j + 1][i] = pq.top().first;
			pq.pop();
			j += 2;
		}
		if (maxval > pq.size()) {
			for (int j = pq.size(); j <= maxval; j++) {
				map[j][i] = 0;
			}
		}
		else
			maxval = pq.size();
		vector<vector<int> > monsters;
		monsters[0][0];
		queue<int> q;
		q.front();
	
	}
}
void calc_r() {
	priority_queue<pair<int, int>> pq;
	int maxval = 0;
	for (int i = 1; i <= now_r; i++) {
		for (int j = 1; j <= now_c; j++) {
			number[map[i][j]]++;
		}
		for (int i = 1; i < 101; i++) {
			if (number[i] > 0) {
				pq.push({ number[i],i });
			}
		}
		int j = 1;
		while (!pq.empty()) {
			map[i][j] = pq.top().second;
			map[i][j + 1] = pq.top().first;
			pq.pop();
			j += 2;
		}
		if (maxval > pq.size()) {
			for (int j = pq.size(); j <= maxval; j++) {
				map[i][j] = 0;
			}
		}
		else
			maxval = pq.size();
	}
	
}
int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	now_r = 3, now_c = 3;
	int answer = 0;
	while (map[r][c] != k) {
		answer++;
		for (int i = 1; i < 101; i++) {
			number[i] = 0;
		}
		if (now_r >= now_c) {
			calc_r();
		}
		else {
			calc_c();
		}
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
	}
	cout << answer << endl;
}