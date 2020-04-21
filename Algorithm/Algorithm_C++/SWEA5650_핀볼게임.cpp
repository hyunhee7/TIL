/*
	12:00 - 13:30

*/
#include <iostream>
#include <vector>
using namespace std;
int map[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int answer;
int n;
vector<pair<int, int>>warmhole[5];
vector<pair<int, int>> start;
int start_x, start_y;
int CheckDir(int x, int y, int block, int dir) {
	if (block == 1) {
		if (dir == 0) return 1;
		if (dir == 1) return 3;
		if (dir == 2) return 0;
		if (dir == 3) return 2;
	}
	else if (block == 2) {
		if (dir == 0) return 3;
		if (dir == 1) return 0;
		if (dir == 2) return 1;
		if (dir == 3) return 2;
	}
	else if (block == 3) {
		if (dir == 0) return 2;
		if (dir == 1) return 0;
		if (dir == 2) return 3;
		if (dir == 3) return 1;
	}
	else if (block == 4) {
		if (dir == 0) return 1;
		if (dir == 1) return 2;
		if (dir == 2) return 3;
		if (dir == 3) return 0;
	}
	else if (block == 5) {
		if (dir == 0) return 1;
		if (dir == 1) return 0;
		if (dir == 2) return 3;
		if (dir == 3) return 2;
	}

	return dir;
}
void dfs(int x, int y, int dir, int res) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	//그냥 벽인 경우
	if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
		int s = (res * 2) + 1;
		if (answer < s) answer = s;
		return;
	}
	else if (nx == start_x && ny == start_y) {
		if (res > answer) answer = res;
		return;
	}
	//0인 경우
	else if (map[nx][ny] == 0) {
		dfs(nx, ny, dir, res);
	}
	//dir꺾이는 경우
	else if (map[nx][ny] > 0 && map[nx][ny] < 6) {
		dir = CheckDir(nx, ny, map[nx][ny], dir);
		dfs(nx, ny, dir, res + 1);
	}
	//웜홀인 경우
	else if (map[nx][ny] > 5 && map[nx][ny] < 11) {
		int _x = warmhole[map[nx][ny] - 6].at(0).first;
		int _y = warmhole[map[nx][ny] - 6].at(0).second;
		if (_x == nx && _y == ny) {
			_x = warmhole[map[nx][ny] - 6].at(1).first;
			_y = warmhole[map[nx][ny] - 6].at(1).second;
		}
		dfs(_x, _y, dir, res);
	}	
	//블랙홀일 경우
	else if (map[nx][ny] == -1) {
		if (res > answer) answer = res;
		return;
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		answer = 0;
		for (int i = 0; i < 5; i++) {
			warmhole[i].clear();
		}
		start.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					warmhole[map[i][j] - 6].push_back({ i,j });
				}
				else if (map[i][j] == 0) {
					start.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < 4; j++) { //dir
				start_x = start[i].first;
				start_y = start[i].second;
				dfs(start_x, start_y, j, 0);
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
}