/*
	10:45 - 12:15
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[14][21];
int k;
int d, w;
int answer;
bool isAns = false;
bool test() {
	/*cout << "----------" << endl;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}*/
	
	//k개 연속 검사
	int total = 0; bool isFin = false;
	for (int i = 0; i < w; i++) {
		int start = map[0][i];
		int num = 1;
		isFin = false;
		for (int j = 1; j < d; j++) {
			
			if (start == map[j][i]) {
				num++;
			}
			else {
				if (j >= d - k + 1) {
					isFin = true;
					break;
				}
				start = map[j][i];
				num = 1;
				continue;
			}
			//cout << "i: " << i << ", j: " << j <<"num: " << num << endl;
			if (num == k) {
				total++;
				break;
			}
		}
		if (isFin) break;
	}
	//cout << total << endl;
	if (total == w) return true;
	return false;
	
}
void dfs(int index, int cnt, int val) {
	if (isAns) return;
	if (cnt == val) {
		//검사하기
		isAns = test();
		if (isAns) answer = val;
		return;
	}
	if (index >= d)return;
	//투약하기
	//현재칸 넘기기
	dfs(index + 1, cnt, val);
	//cnt칸 복사
	int tmp[21];
	for (int i = 0; i < w; i++) {
		tmp[i] = map[index][i];
	}
	//주입후 dfs
	for (int i = 0; i < w; i++) {
		map[index][i] = 0;
	}
	dfs(index + 1, cnt + 1, val);
	for (int i = 0; i < w; i++) {
		map[index][i] = 1;
	}
	dfs(index + 1, cnt + 1, val);
	//원상태 복귀
	for (int i = 0; i < w; i++) {
		map[index][i] = tmp[i];
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		answer = 0;
		isAns = false;
		//입력
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		if (k > 1) {
			//val : 최대 투약 횟수
			for (int val = 0; val <= d; val++) {
				//투약
				if (val == 0) {
					if (test()) break;
				}
				else if (val > 0) dfs(0, 0, val);
				if (isAns) break;
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
}