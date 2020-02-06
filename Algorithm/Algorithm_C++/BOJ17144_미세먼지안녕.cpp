/*
	11:45 - 13:15
*/
#include <iostream>
#include <vector>
using namespace std;
int r, c, t;
int map[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int, int>> cleaner;

int main() {
	//입력
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				cleaner.push_back(make_pair(i, j));
			}
		}
	}
	//시간 흐르기
	for (int time = 0; time < t; time++) {
		//1. 먼지 확산
		int tmp_map[51][51];
		for (int i = 0; i < r; i++) {
			fill(tmp_map[i], tmp_map[i] + c, 0);
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] > 0) {
					//1. 퍼뜨린 먼지 
					int count = 0;
					int val = map[i][j] / 5;
					for (int p = 0; p < 4; p++) {
						int nx = i + dx[p];
						int ny = j + dy[p];
						if (nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny]==-1)continue;
						count++;
						tmp_map[nx][ny] += val;
					}
					map[i][j] = map[i][j] - (val * count);
				}
			}
		}
		//cout << "1--------------" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				map[i][j] += tmp_map[i][j];
				//cout << map[i][j] << ' ';
			}
			//cout << endl;
		}
		//2. 공기청정기 작동
		int ax = cleaner[0].first, ay = cleaner[0].second;
		int bx = cleaner[1].first, by = cleaner[1].second;
		//위(반시계)
		//(0,0)~(ax,0)
		for (int i = ax-1; i>0; i--) {
			map[i][0] = map[i-1][0];
		}
		//(0,c-1)~(0,0)
		for (int i = 0; i < c - 1; i++) {
			map[0][i] = map[0][i + 1];
		}
		//(ax,c-1)~(0,c-1)
		for (int i = 0; i < ax; i++) {
			map[i][c - 1] = map[i + 1][c - 1];
		}
		//(ax,1)~(ax,c-1)
		for (int i = c - 1; i >= 1; i--) {
			if (map[ax][i - 1] == -1) {
				map[ax][i] = 0;
			}else
				map[ax][i] = map[ax][i - 1];
		}
		

		//아래(시계)
		//(r-1,0)~(bx,0)
		for (int i = bx+1; i < r - 1; i++) {
			map[i][0] = map[i + 1][0];
		}
		//(r-1,c-1)~(r-1,0)
		for (int i = 0; i < c - 1; i++) {
			map[r - 1][i] = map[r - 1][i + 1];
		}
		//(bx,c-1)~(r-1,c-1)
		for (int i = r - 1; i > bx; i--) {
			map[i][c - 1] = map[i - 1][c - 1];
		}
		//(bx,1)~(bx,c-1)
		for (int i = c - 1; i >= 1; i--) {
			if (i == 1) {
				map[bx][i] = 0;
			}
			else {
				map[bx][i] = map[bx][i - 1];
			}
		}
		/*cout << "2--------------" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}*/
	}
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 0 || map[i][j]==-1) continue;
			answer += map[i][j];
		}
	}
	cout << answer;
}