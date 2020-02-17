/*
	11:10 - 12:40
*/
#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int n, k, l;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int map[101][101];
bool visited[101][101];
int t[10001]; //1시계 -1반시계
int main() {
	cin >> n;
	cin >> k;
	memset(t, 0, sizeof(t));
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		if (c == 'L') { //반시계
			t[x] = -1;
		}
		else {			//시계
			t[x] = 1;
		}
	}
	int time = 0;
	int len = 1;
	int now = 0; 
	deque<pair<int,int>> snake;
	snake.push_back({ 1,1 });
	visited[1][1] = true;
	while (true) {
		
		
		int dir = t[time];
		if (dir == 1 || dir == -1) {
			now += dir;
			if (now > 3) now = 0;
			else if (now < 0) now = 3;
		}
		time++;
		//cout << time << endl;
		int nx = snake.front().first + dx[now];
		int ny = snake.front().second + dy[now];
		//cout << nx << " " << ny <<endl;
		//범위 벗어난 경우
		if (nx<1 || ny<1 || nx>n || ny>n) break;
		if (visited[nx][ny])break;
		//사과 안먹는 경우 꼬리 빼줌
		if (map[nx][ny] == 0) {
			int bx = snake.back().first;
			int by = snake.back().second;
			visited[bx][by] = false;
			snake.pop_back();
		}
		//사과 먹는 경우 사과 없어짐
		else {
			map[nx][ny] = 0;
		}
		snake.push_front({ nx,ny });
		visited[nx][ny] = true;
		/*for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				cout << visited[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "-------" << endl;*/
	}
	cout << time << endl;
}