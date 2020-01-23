/*
	14:00 - 15:30
*/
#include <iostream>
#include <math.h>
using namespace std;
int n, m, c;
int map[11][11];
int res, answer;
int maxval;
void comb(int x, int y, int cnt, int total, int resval) {
	if (cnt >= m) return;
	if (y >= n) return;
	if (total + map[x][y] > c) return;

	resval += pow(map[x][y], 2);
	//cout << "resva: " << resval << endl;
	if (resval > maxval) maxval = resval;

	comb(x, y + 1, cnt + 1, total, resval - pow(map[x][y], 2));
	comb(x, y + 1, cnt + 1, total + map[x][y], resval);
}
void calc(int firstX, int firstY, int secondX, int secondY) {

	//첫번째 벌통
	int val = 0;
	maxval = 0;
	res = 0;
	for (int i = 0; i < m; i++) {
		//cout << "i: " << i << endl;
		val += map[firstX][firstY + i];
	}
	//cout << "val: "<<val<<endl;
	if (val > c) {
		//벌통선택
		comb(firstX, firstY, 0, 0, 0);
		res += maxval;
	}
	else {
		for (int i = 0; i < m; i++) {
			res += pow(map[firstX][firstY + i], 2);
		}
	}
	//두번째 벌통
	val = 0;
	maxval = 0;
	for (int i = 0; i < m; i++) {
		val += map[secondX][secondY + i];
	}
	if (val > c) {
		//벌통선택
		comb(secondX, secondY, 0, 0, 0);
		res += maxval;
	}
	else {
		for (int i = 0; i < m; i++) {
			res += pow(map[secondX][secondY + i], 2);
		}
	}
	//cout << "후 : ("<<firstX<<","<<firstY<<") "<< "(" << secondX << "," << secondY << ") " <<"res: "<< res << endl;
	if (res > answer) answer = res;
}
void chooseanother(int x, int y) {
	for (int i = y + m; i <= n - m; i++) {
		if (i >= n) break;
		calc(x, y, x, i);
	}
	for (int i = x + 1; i < n; i++) {
		for (int j = 0; j <= n - m; j++) {
			calc(x, y, i, j);
		}
	}
}
int main() {
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		for (int i = 0; i < 11; i++) {
			fill(map[i], map[i] + 11, 0);
		}
		n = 0, m = 0, c = 0;
		res = 0, answer = 0;
		//입력
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		//첫번째 벌통
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				chooseanother(i, j);
			}
		}
		//cout << answer;
		cout << "#" << t << ' ' << answer << endl;
	}
}