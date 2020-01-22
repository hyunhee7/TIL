/*
11:30 - 13 : 00
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int answer = 0;
int map[9][9];
bool visited[9][9];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y, bool isCut, int cnt) {
	visited[x][y] = true;
	//cout << x << ' ' << y <<' ' <<cnt <<endl;
	if (answer < cnt) answer = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		//경사로
		if (map[x][y] > map[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny, isCut, cnt + 1);
		}
		//깎기
		if (map[x][y] <= map[nx][ny] && !visited[nx][ny] && !isCut) {
			if (map[nx][ny] - map[x][y] < k) {
				int tmp = map[nx][ny];
				map[nx][ny] = map[x][y]-1;
				isCut = true;
				dfs(nx, ny, isCut, cnt + 1);
				isCut = false;
				map[nx][ny] = tmp;
			}
		}
	}
	visited[x][y] = false;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		n = 0; k = 0, answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		//입력
		cin >> n >> k;
		int mval = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] > mval) {
					mval = map[i][j];
				}
			}
		}
		//등산로 조성
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int i = 0; i < n; i++) fill(visited[i], visited[i] + n, false);
				if (map[i][j] == mval) {
					dfs(i, j, false, 1);
					//cout << "------" << endl;
				}
			}
		}
		cout << "#"<< t << ' ' << answer << endl;
	}
}