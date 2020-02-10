/*
	8:40 - 10:10
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int r, c, k;
int map[101][101];
int val[101]; //row:index col:È½¼ö
int main() {
	cin >> r >> c >> k;
	int row = 3, col = 3;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	int answer = -1;
	for (int time = 0; time < 101; time++) {
		if (map[r][c] == k) {
			answer = time;
			break;
		}
		if (row >= col) {
			for (int i = 1; i <= row; i++) {
				priority_queue<pair<int, int>> pq;
				memset(val, 0, sizeof(val));
				for (int j = 1; j <= col; j++) {
					if (map[i][j]) {
						val[map[i][j]]++;
						map[i][j] = 0;
					}
				}
				for (int j = 1; j <= 100; j++) {
					if (val[j]) pq.push(make_pair(-val[j], -j));
				}
				int len = pq.size() * 2;
				col = max(col, len);
				for(int j=1;j<=len;j+=2){
					map[i][j] = -pq.top().second;
					map[i][j + 1] = -pq.top().first;
					pq.pop();
				}
			}
		}
		else {
			for (int i = 1; i <= col; i++) {
				priority_queue<pair<int, int>> pq;
				memset(val, 0, sizeof(val));
				for (int j = 1; j <= row; j++) {
					if (map[j][i]) {
						val[map[j][i]]++;
						map[j][i] = 0;
					}
				}
				for (int j = 1; j <= 100; j++) {
					if (val[j]) {
						pq.push(make_pair(-val[j], -j));
					}
				}
				int len = pq.size() * 2;
				row = max(row, len);
				for (int j = 1; j <= len; j += 2) {
					map[j][i] = -pq.top().second;
					map[j + 1][i] = -pq.top().first;
					pq.pop();
				}
			}
		}
	}
	cout << answer;
}