#include <iostream>
using namespace std;
/*
	15:45 - 17:15
*/
int n, m, k;
int map[51][51];
int order[7][3];
bool isFin[7];
int answer = 987654321;
void dfs(int index, int cnt, int (*tmap)[51]) {
	int tmp[51][51];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tmp[i][j] = tmap[i][j];
		}
	}
	//회전
	int r = order[index][0];
	int c = order[index][1];
	int s = order[index][2];
	int ar = r - s; int ac = c - s;
	int br = r - s; int bc = c + s;
	int cr = r + s; int cc = c + s;
	int dr = r + s; int dc = c - s;
	for (int i = 0; i < s; i++) {
		int val = tmp[ar][ac];
		//좌
		for (int i = ar; i < dr; i++) {
			tmp[i][ac] = tmp[i + 1][ac];
		}
		//하
		for (int i = dc; i < cc; i++) {
			tmp[dr][i] = tmp[dr][i + 1];
		}
		//우
		for (int i = cr; i > br; i--) {
			tmp[i][cc] = tmp[i - 1][cc];
		}
		//상
		for (int i = bc; i > ac + 1; i--) {
			tmp[br][i] = tmp[br][i - 1];
		}
		tmp[ar][ac + 1] = val;

		ar += 1; ac += 1;
		br += 1; bc -= 1;
		cr -= 1; cc -= 1;
		dr -= 1; dc += 1;
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << tmp[i][j] << ' ';
		}
		cout << endl;
	}*/
	//다음
	if (cnt == k - 1) {
		int res = 987654321;
		for (int i = 1; i <= n; i++) {
			int v = 0;
			for (int j = 1; j <= m; j++) {
				v += tmp[i][j];
			}
			//cout << "v:" << v << endl;
			if (v < res)res = v;
		}
		//cout << "res:" << res << endl;
		if (res < answer) answer = res;
		return;
	}
	for (int i = 1; i <= k; i++) {
		if (!isFin[i]) {
			isFin[i] = true;
			//cout << "i:" << i << endl;
			dfs(i, cnt + 1, tmp);
			isFin[i] = false;
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> order[i][0] >> order[i][1] >> order[i][2];
	}
	for (int i = 1; i <= k; i++) {
		isFin[i] = false;
	}
	for (int i = 1; i <= k; i++) {
		if (!isFin[i]) {
			isFin[i] = true;
			dfs(i, 0, map);
			isFin[i] = false;
		}
	}
	cout << answer << endl;
}