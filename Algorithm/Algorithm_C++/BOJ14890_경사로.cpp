/*
	11:00 - 12:30
*/
#include <iostream>
using namespace std;
int n, l;
int answer = 0;
int map[101][101];
int main() {
	//입력
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	//가로
	for (int i = 0; i < n; i++) {
		bool visited[101];
		for (int j = 0; j < n; j++) {
			visited[j] = false;
		}
		bool isImpossible = false;
		int num = 0;
		int flat = 0;
		for (int j = 0; j < n - 1; j++) {
			if (isImpossible) break;
			if (map[i][j] == map[i][j + 1]) {
				flat++;
				continue;
			}
			//다음 칸 높을 경우 j, j-1 체크
			if (map[i][j] + 1 == map[i][j + 1]) {
				num = 0;
				int val = map[i][j];
				int start = j + 1 - l;
				if (j + 1 - l < 0) {
					start = 0;
				}
				for (int k = start; k < j + 1; k++) {
					//경사로 세웠는지 여부 체크
					if (!visited[k] && map[i][k] == val) {
						num++;
						visited[k] = true;
					}
					else {
						isImpossible = true;
						break;
					}
				}
				if (num != l) isImpossible = true;
			}
			else if (map[i][j] - 1 == map[i][j + 1]) {
				num = 0;
				int val = map[i][j + 1];
				int fin = j + l + 1;
				if (fin > n) {
					fin = n;
				}
				for (int k = j + 1; k < fin; k++) {
					if (!visited[k] && map[i][k] == val) {
						num++;
						visited[k] = true;
					}
					else {
						isImpossible = true;
						break;
					}
				}
				if (num != l) isImpossible = true;
			}
			else {
				isImpossible = true;
				break;
			}
		}

		if (flat == n - 1) {
			answer++;
		}else if (!isImpossible) {
			answer++;
		}
			
	}
	//세로
	for (int i = 0; i < n; i++) {
		bool visited[101];
		for (int j = 0; j < n; j++) {
			visited[j] = false;
		}
		bool isImpossible = false;
		int num = 0;
		int flat = 0;
		for (int j = 0; j < n - 1; j++) {
			if (isImpossible) break;
			if (map[j][i] == map[j+1][i]) {
				flat++;
				continue;
			}
			//다음 칸 높을 경우 j, j-1 체크
			if (map[j][i] + 1 == map[j + 1][i]) {
				num = 0;
				int val = map[j][i];
				int start = j + 1 - l;
				if (j + 1 - l < 0) {
					start = 0;
				}
				for (int k = start; k < j + 1; k++) {
					//경사로 세웠는지 여부 체크
					if (!visited[k] && map[k][i] == val) {
						num++;
						visited[k] = true;
					}
					else {
						isImpossible = true;
						break;
					}
				}
				if (num != l) isImpossible = true;
			}
			else if (map[j][i] - 1 == map[j + 1][i]) {
				num = 0;
				int val = map[j+1][i];
				int fin = j + l + 1;
				if (fin >= n) {
					fin = n;
				}
				for (int k = j + 1; k < fin; k++) {
					if (!visited[k] && map[k][i] == val) {
						num++;
						visited[k] = true;
					}
					else {
						isImpossible = true;
						break;
					}
				}
				if (num != l) isImpossible = true;
			}
			else {
				isImpossible = true;
				break;
			}
		}

		if (flat == n - 1) {
			answer++;
		}else if (!isImpossible) {
			answer++;
		}

	}
	cout << answer;
}