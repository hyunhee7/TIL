/*
	9:30 - 11:00
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
int map[101][101];
int answer = 0;
int cnt[101];
vector<pair<int, int>> list;
int lineSize[101];
bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}
int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	int row = 3;
	int col = 3;
	while (answer<=100) {
		list.clear();
		/*cout << row << " " << col << endl;
		cout << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}*/
		if (map[r-1][c-1] == k) {
			break;
		}
		int maxCOL = 0;
		int maxROW = 0;
		//R연산
		if (row >= col) {
			int index = 0;
			memset(lineSize, 0, sizeof(lineSize));
			//연산
			for (int i = 0; i < row; i++) {
				memset(cnt, 0, sizeof(cnt));
				list.clear();
				index = 0;
				for (int j = 0; j < col; j++) {
					cnt[map[i][j]]++;
				}
				for (int j = 1; j < 101; j++) {
					if (cnt[j] > 0) {
						list.push_back({ cnt[j],j });
					}
				}
				lineSize[i] = list.size() * 2;
				if (list.size() * 2 > maxCOL)maxCOL = list.size() * 2;
				//정렬
				sort(list.begin(), list.end(), comp);
				
				//배열 넣기
				for (int j = 0; j < list.size(); j++) {
					map[i][index] = list[j].second;
					map[i][index + 1] = list[j].first;
					index += 2;
				}
			}
			col = maxCOL;
			for (int i = 0; i < row; i++) {
				for (int j = lineSize[i]; j < col; j++) {
					map[i][j] = 0;
				}
			}
		}
		//C연산
		else {
			//연산
			int index = 0;
			memset(lineSize, 0, sizeof(lineSize));
			for (int i = 0; i < col; i++) {
				memset(cnt, 0, sizeof(cnt));
				index = 0;
				list.clear();
				for (int j = 0; j < row; j++) {
					cnt[map[j][i]]++;
				}
				for (int j = 1; j < 101; j++) {
					if (cnt[j] > 0) {
						list.push_back({ cnt[j],j });
					}
				}
				lineSize[i] = list.size() * 2;
				if (list.size() * 2 > maxROW)maxROW = list.size() * 2;
				//정렬
				sort(list.begin(), list.end(), comp);
				//배열 넣기
				/*for (int p = 0; p < list.size(); p++) {
					cout << list[p].second << " " << list[p].first << endl;
				}*/
				
				for (int j = 0; j < list.size(); j++) {
					map[index][i] = list[j].second;
					map[index + 1][i] = list[j].first;
					index += 2;
				}
			}
			row = maxROW;
			for (int i = 0; i < col; i++) {
				for (int j = lineSize[i]; j < row; j++) {
					map[j][i] = 0;
				}
			}
		}
		answer++;
	}
	if (answer > 100) answer = -1;
	cout << answer << endl;
}