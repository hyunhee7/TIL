/*
	11:55 - 13:25
*/
#include <iostream>
using namespace std;
int n;
int map[21][21];
bool visited[21][21];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
bool dessert[101];
int answer;
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < 101; i++) {
		dessert[i] = false;
	}
}
void dfs(int start_x, int start_y, int x, int y, int dir, int num) {
	if (start_x == x && start_y == y && dir==3) {
		//cout << x << " " << y << " " <<num<< endl;
		if (answer < num) {
			answer = num;
		}
		return;
	}
	if (visited[x][y] || dessert[map[x][y]])return;
	visited[x][y] = true;
	dessert[map[x][y]] = true;
	num++;

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
		dfs(start_x, start_y, nx, ny, dir, num);
	}
	nx = x + dx[dir + 1];
	ny = y + dy[dir + 1];
	if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
		dfs(start_x, start_y, nx, ny, dir + 1, num);
	}
	visited[x][y] = false;
	dessert[map[x][y]] = false;
	num--;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		answer = -1;
		for (int i = 1; i < 101; i++) {
			dessert[i] = false;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				init();
				dfs(i, j, i, j, 0, 0);
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
}