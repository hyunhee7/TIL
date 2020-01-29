/*
	11:00-12:30
*/
#include <iostream>
#include <vector>
using namespace std;
bool map[101][101];
int note[21][4];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int nxtx[] = { 1,0,-1,0 };
int nxty[] = { 0,-1,0,1 };
int answer = 0;
void dfs(int cnt, vector<pair<int, int>> v, int depth) {
	if (cnt == depth) {
		return;
	}
	int vsize = v.size();
	int x = v[vsize - 1].first;
	int y = v[vsize - 1].second;
	for (int i = vsize - 1; i > 0; i--) {
		int vx = v[i - 1].first - v[i].first;
		int vy = v[i - 1].second - v[i].second;
		int nx, ny;
		if (vx == 1 && vy == 0) {
			nx = x + nxtx[1];
			ny = y + nxty[1];
		}
		else if (vx == 0 && vy == -1) {
			nx = x + nxtx[2];
			ny = y + nxty[2];
		}
		else if (vx == -1 && vy == 0) {
			nx = x + nxtx[3];
			ny = y + nxty[3];
		}
		else {
			nx = x + nxtx[0];
			ny = y + nxty[0];
		}
		map[nx][ny] = true;
		v.push_back(make_pair(nx, ny));
		x = nx;
		y = ny;
	}
	dfs(cnt + 1, v, depth);
}
int main() {
	//입력
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> note[i][0] >> note[i][1] >> note[i][2] >> note[i][3];
	}
	//커브 그리기
	for (int i = 0; i < n; i++) {
		//0세대
		int y = note[i][0]; int x = note[i][1];
		int dir = note[i][2]; int depth = note[i][3];
		map[x][y] = true;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		map[nx][ny] = true;

		vector<pair<int, int>> v;
		v.push_back(make_pair(x, y)); v.push_back(make_pair(nx, ny));
		//다음 세대
		dfs(0, v, depth);
		/*for (int p = 0; p < 12; p++) {
			for (int q = 0; q < 12; q++) {
				cout << map[p][q] << ' ';
			}
			cout << endl;
		}
		cout << "-------------------" << endl;*/
	}

	//정사각형 갯수 구하기
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			//cout << map[i][j] << ' ';
			if (map[i][j] == true &&
				map[i + 1][j] == true &&
				map[i][j + 1] == true &&
				map[i + 1][j + 1] == true) {
				answer++;
			}
		}
		//cout << endl;
	}

	cout << answer;
}