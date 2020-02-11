/*
	8:40 - 10:10
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, answer = 987654321;
int map[21][21];
int sep[21][21];
int d1, d2;
int cnt[6];
vector<int> xlist;
vector<int> ylist;
int x, y;
void makexy() {
	//x
	for (int i = 1; i < n; i++) {
		if (i + d1 + d2 <= n && i < i + d1 + d2) {
			xlist.push_back(i);
		}
	}
	//y
	for (int i = 1; i < n; i++) {
		if (i - d1 < i && i + d2 <= n && i < i + d2) {
			ylist.push_back(i);
		}
	}
}
void makeline() {
	//경계선 만들기
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			sep[i][j] = 0;
		}
	}
	for (int i = 1; i < 6; i++) {
		cnt[i] = 0;
	}


	//if (x + d1 + d2 > n || y - d1 < 0 || y + d2 > n) return;
	for (int i = 0; i <= d1; i++) {
		sep[x + i][y - i] = 5;
		sep[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		sep[x + i][y + i] = 5;
		sep[x + d1 + i][y - d1 + i] = 5;
	}
	sep[x][y] = 5;
	for (int i = 1; i <= n; i++) {
		int start, end, isOK = 0;
		for (int j = 1; j <= n; j++) {
			if (sep[i][j] == 5 && isOK == 0) {
				isOK++;
				start = j;
			}
			else if (sep[i][j] == 5 && isOK == 1) {
				isOK = 2;
				end = j;
			}
		}
		if (isOK != 2)continue;
		for (int j = start; j < end; j++) {
			sep[i][j] = 5;
		}
	}
	//선거구 표시
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (sep[i][j] > 0) continue;
			if (i >= 1 && i < x + d1 && j >= 1 && j <= y) {
				sep[i][j] = 1;
				//cnt[1] += map[i][j];
			}
			else if (i >= 1 && i <= x + d2 && j > y&& j <= n) {
				sep[i][j] = 2;
				//cnt[2] += map[i][j];
			}
			else if (i >= x + d1 && i <= n && j >= 1 && j < y - d1 + d2) {
				sep[i][j] = 3;
				//cnt[3] += map[i][j];
			}
			else if (i > x + d2 && i <= n && j >= y - d1 + d2 && j <= n) {
				sep[i][j] = 4;
				//cnt[4] += map[i][j];
			}
			//else {
			//	sep[i][j] = 5;
				//cnt[5] += map[i][j];
			//}
			//cout << x << " " << y << " " << d1 << " " << d2 << endl;
		}
	}

	//
	//cnt[5] += sep[x][y];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (sep[i][j] == 1) {
				cnt[1] += map[i][j];
			}
			else if (sep[i][j] == 2) {
				cnt[2] += map[i][j];
			}
			else if (sep[i][j] == 3) {
				cnt[3] += map[i][j];
			}
			else if (sep[i][j] == 4) {
				cnt[4] += map[i][j];
			}
			else {
				cnt[5] += map[i][j];
			}
		}
	}
	//min, max 구하기
	int maxsep = 0, minsep = 987654321;
	for (int i = 1; i <= 5; i++) {
		if (cnt[i] > maxsep) {
			maxsep = cnt[i];
		}
		if (cnt[i] < minsep) {
			minsep = cnt[i];
		}
	}

	//차이 answer 구하기
	if (maxsep - minsep < answer) {
		/*cout << x << " " << y << " " << d1 << " " << d2 << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << sep[i][j] << " ";
			}
			cout << endl;
		}
		cout << "x,y : " << x << " " << y << endl;*/
		answer = maxsep - minsep;
	}
}
int main() {
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			sep[i][j] = 0;
		}
	}
	//d1,d2정하기
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			d1 = i;
			d2 = j;
			xlist.clear();
			ylist.clear();
			makexy();
			//cout << xlist.size() << " " << ylist.size() << endl;
			if (xlist.size() == 0 || ylist.size() == 0) continue;
			//cout << i << " " << j << endl;
			//cout << "d1,d2: "<<d1 << " " << d2 << endl;
			for (int p = 0; p < xlist.size(); p++) {
				for (int q = 0; q < ylist.size(); q++) {
					x = xlist[p];
					y = ylist[q];
					makeline();
				}
			}

		}
	}
	//인구 ismin = maxval - minval 
	cout << answer << endl;
}