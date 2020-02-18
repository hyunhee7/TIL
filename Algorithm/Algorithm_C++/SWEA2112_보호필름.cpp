/*
	13:35 - 15:05
*/
#include <iostream>
using namespace std;
int answer = 987654321;
int map[14][22];
int d, w, k;
bool isFin = false;
int list[14];
void dfs(int cnt, int valu, int res) {
	
	if (valu == res) {
		if (isFin) return;
		int val = 0;
		//연속확인
		for (int i = 1; i <= w; i++) {
			bool isOK = false;
			int start = 1;
			int tmp = 1;
			for (int j = 2; j <= d; j++) {
				if (map[j][i] == map[start][i]) {
					tmp++;
				}
				else {
					start = j;
					tmp = 1;
				}
				if (k == tmp) {
					isOK = true;
					val++;
					break;
				}
			}
			if (!isOK) break;
		}
		if (val == w) {
			cout << cnt << endl;
			isFin = true;
		}
		return;
	}
	if (cnt > d ) return;
	//투약할 위치 지정

	dfs(cnt + 1, valu, res);
	int color[21];
	for (int i = 1; i <= w; i++) {
		color[i] = map[cnt][i];
	}

	for (int i = 1; i <= w; i++) {
		map[cnt][i] = 0;
	}
	dfs(cnt + 1, valu + 1, res);

	for (int i = 1; i <= w; i++) {
		map[cnt][i] = 1;
	}
	dfs(cnt + 1, valu + 1, res);

	for (int i = 1; i <= w; i++) {
		map[cnt][i] = color[i];
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		answer = 987654321;
		isFin = false;
		cin >> d >> w >> k;
		for (int i = 1; i <= d; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}
		for (int r = 0; r < d; r++) {
			dfs(1, 0, r);

			if (isFin) {
				answer = r;
				break;
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
}