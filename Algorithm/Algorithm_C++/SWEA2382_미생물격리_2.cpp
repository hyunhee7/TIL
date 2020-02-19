/*
	15:30 - 17:00
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
struct Cell {
	int index;
	int x, y;
	int num;
	int dir;
};
vector<Cell> cells;
vector<Cell> map[101][101];
int n, m, k;
int answer;
void move() {
	//군집 삭제
	for (int i = 1; i <= k; i++) {
		if (cells[i].num >= 0) {
			map[cells[i].x][cells[i].y].clear();
		}
	}
	//군집 이동
	for (int i = 1; i <= k; i++) {
		if (cells[i].num <= 0)continue;
		//다음 좌표 구하기
		Cell cell = cells[i];
		int x = cell.x;
		int y = cell.y;
		int num = cell.num;
		int dir = cell.dir;
		//범위 체크
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || ny <= 0 || nx >= n - 1 || ny >= n - 1) {
			//세포 반감, 방향변경
			if (dir == 1 || dir == 2) {
				cells[i].dir = 3 - dir;
			}
			else {
				cells[i].dir = 7 - dir;
			}
			cells[i].num = num/2;
		}
		//표시하기
		cells[i].x = nx;
		cells[i].y = ny;
		map[cells[i].x][cells[i].y].push_back(cells[i]);
	}
	bool visited[1001];
	memset(visited, false, sizeof(visited));
	//같은 위치 합치기
	for (int i = 1; i <= k; i++) {
		if (visited[i] == true) continue;
		Cell cell = cells[i];
		visited[cell.index] = true;
		if (map[cell.x][cell.y].size() > 1) {
			int x = cell.x;
			int y = cell.y;
			int maxnum = cell.num;
			int maxindex = cell.index;
			int total = cell.num;
			int dir = cell.dir;
			cells[i].num = 0;
			for (int j = 0; j < map[x][y].size(); j++) {
				if (map[x][y][j].index == cell.index) continue;
				visited[map[x][y][j].index] = true;
				Cell ncell = map[x][y][j];
				//cout << "plu:" << ncell.num<<endl;
				total += ncell.num;
				cells[ncell.index].num = 0;
				if (ncell.num > maxnum) {
					maxnum = ncell.num;
					maxindex = ncell.index;
					dir = ncell.dir;
				}
			}
			cells[maxindex].num = total;
		}
	}

}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		answer = 0;
		cells.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j].clear();
			}
		}
		cin >> n >> m >> k;
		cells.resize(k+1);
		
		for (int i = 1; i <= k; i++) {
			Cell cell;
			cell.index = i;
			cin >> cell.x >> cell.y >> cell.num >> cell.dir;
			cells[i] = cell;
		}
		/*for (int i = 1; i <= k; i++) {
			cout << cells[i].index << " " << cells[i].num << " " << cells[i].dir << endl;
		}
		cout << "--------" << endl;*/
		for (int time = 0; time < m; time++) {
			move();
			/*for (int i = 1; i <= k; i++) {
				cout << cells[i].index << " " << cells[i].num << " " << cells[i].dir << endl;
			}
			cout << "--------" << endl;*/
		}

		//남은 미생물 수
		for (int i = 1; i <= k; i++) {
			if (cells[i].num > 0) {
				answer += cells[i].num;
			}
		}
		cout << "#" << "1" << " " << answer << endl;
	}
}