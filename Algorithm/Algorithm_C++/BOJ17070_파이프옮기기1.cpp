#include <iostream>
#include <vector>
using namespace std;
int n;
int map[17][17];
bool visited[17][17];
int dx[] = { 0,1,1 };
int dy[] = { 1,1,0 }; //가로, 대각, 세로
int answer = 0;
void dfs(int bx, int by, int x, int y, int dir) {
	if (x == n-1 && y == n-1) {
		answer++;
		return;
	}
	visited[bx][by] = 0;
	//현재그대로
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
		if (dir != 1) {
			if (map[nx][ny] == 0 && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				dfs(x, y, nx, ny, dir);
				visited[nx][ny] = 0;
			}
		}
		else {
			if (map[nx][ny] == 0 && map[nx - 1][ny] == 0 && map[nx][ny - 1] == 0 &&
				!visited[nx][ny] && !visited[nx - 1][ny] && !visited[nx][ny - 1]) {
				visited[nx][ny] = 1;
				visited[nx - 1][ny] = 1;
				visited[nx][ny - 1] = 1;
				dfs(x, y, nx, ny, dir);
				visited[nx][ny] = 0;
				visited[nx - 1][ny] = 0;
				visited[nx][ny - 1] = 0;
			}
		}
		
	}
	//가로, 세로
	if (dir == 1) {
		nx = x + dx[dir - 1];
		ny = y + dy[dir - 1];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (map[nx][ny] == 0 && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				dfs(x, y, nx, ny, dir - 1);
				visited[nx][ny] = 0;
			}
		}
		nx = x + dx[dir + 1];
		ny = y + dy[dir + 1];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (map[nx][ny] == 0 && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				dfs(x, y, nx, ny, dir + 1);
				visited[nx][ny] = 0;
			}
		}
	}
	//45도
	else {
		nx = x + dx[1];
		ny = y + dy[1];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (map[nx][ny] == 0 && map[nx-1][ny] == 0 && map[nx][ny-1] == 0 &&
				!visited[nx][ny] && !visited[nx-1][ny] && !visited[nx][ny-1]) {
				visited[nx][ny] = 1;
				visited[nx - 1][ny] = 1;
				visited[nx][ny - 1] = 1;
				dfs(x, y, nx, ny, 1);
				visited[nx][ny] = 0;
				visited[nx - 1][ny] = 0;
				visited[nx][ny - 1] = 0;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	visited[0][0] = 1;
	visited[0][1] = 1;
	dfs(0, 0, 0, 1, 0);
	cout << answer;
}