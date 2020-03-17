/*
	11:30 - 13:00
*/
#include <iostream>
using namespace std;
int n;
int map[21][21];
int answer = 987654321;
void line(int x, int y, int d1, int d2) {
	/*zone[x][y] = 5; zone[x + d1][y - d1] = 5;
	zone[x + d2][y + d2] = 5;
	zone[x + d1][y - d1] = 5;
	zone[x + d1 + d2][y - d1 + d2] = 5;
	zone[x + d2][y + d2] = 5;
	zone[x + d2 + d1][y + d2 - d1] = 5;*/
	int zone[21][21];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			zone[i][j] = 0;
		}
	}
	//1
	for (int i = 0; i <= d1; i++) {
		zone[x + i][y - i] = 5;
		zone[x + d2 + i][y + d2 - i] = 5;
	}
	//2
	for (int i = 0; i <= d2; i++) {
		zone[x + i][y + i] = 5;
		zone[x + d1 + i][y - d1 + i] = 5;
	}
	for (int i = 1; i <= n; i++) {
		int start = 0;
		int end = 0;
		int c = 0;
		for (int j = 1; j <= n; j++) {
			if (zone[i][j] == 5 && c==0) {
				start = j;
				c++;
			}
			else if (c == 1 && zone[i][j] == 5) {
				end = j;
				c++;
			}
		}
		if (c == 2) {
			for (int j = start + 1; j < end; j++) {
				zone[i][j] = 5;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (zone[i][j] != 0)continue;
			if (i < x + d1 && j <= y) zone[i][j] = 1;
			else if (i <= x + d2 && j > y&& j <= n)zone[i][j] = 2;
			else if (i >= x + d1 && i <= n && j < y - d1 + d2)zone[i][j] = 3;
			else if (i > x + d2 && i <= n && j >= y - d1 + d2 && j <= n)zone[i][j] = 4;


		}
	}
	/*cout << "----" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << zone[i][j] << ' ';
		}
		cout << endl;
	}*/
	int val[6];
	for (int i = 1; i < 6; i++)val[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			val[zone[i][j]] += map[i][j];
		}
	}
	int minval = 987654321; int maxval = 0;
	for (int i = 1; i < 6; i++) {
		if (val[i] < minval)minval = val[i];
		if (val[i] > maxval)maxval = val[i];
	}
	if (maxval - minval < answer) answer = maxval - minval;
}
void calc(int x, int y) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x + i + j <= n && y - i >= 1 && y + j <= n) {
				line(x, y, i, j);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//d1,d2값 정하기
			calc(i, j);
		}
	}
	cout << answer;
}