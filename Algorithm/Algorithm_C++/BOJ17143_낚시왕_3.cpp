/*
	14:15 - 15:45
*/
#include <iostream>
#include <vector>
using namespace std;
int r, c, m,answer=0;
int map[101][101];
struct Fish {
	int x, y;
	int speed, dir, z;
	int status;
	Fish() {};
	Fish(int _x, int _y, int _speed, int _dir, int _z, int _status) :
		x(_x), y(_y), speed(_speed), dir(_dir), z(_z), status(_status) {};
};
vector<Fish> fish;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
void fishing(int p) {
	//1. 가장 가까운 상어
	for (int i = 1; i <= r; i++) {
		if (map[i][p] > 0) {
			Fish f = fish[map[i][p]];
			fish[map[i][p]].status = 1; //죽음
			answer += f.z;
			map[f.x][f.y] = 0;
			break;
		}
	}
	for (int p = 1; p < fish.size(); p++) {
		map[fish[p].x][fish[p].y] = 0;
	}
	//2. 상어 이동
	for (int i = 1; i < fish.size(); i++) {
		if (fish[i].status == 1)continue;
		Fish f = fish[i];
		int x = f.x;
		int y = f.y;
		int dir = f.dir;
		int speed = f.speed;
		int nx = x;
		int ny = y;
		
		//dir == 1 or 2
		if (dir == 1 || dir == 2) {
			int rotate = (r - 1) * 2;
			if (speed >= rotate) {
				speed %= rotate;
			}

			for (int j = 0; j < speed; j++) {
				nx += dx[dir];
				if (nx < 1) {
					dir = 3 - dir;
					nx = 2;
				}
				else if (nx > r) {
					dir = 3 - dir;
					nx = r - 1;
				}
			}
		}
		//dir == 3 or 4
		else {
			int rotate = (c - 1) * 2;
			if (speed >= rotate) {
				speed %= rotate;
			}
			for (int j = 0; j < speed; j++) {
				ny += dy[dir];
				if (ny < 1) {
					dir = 7 - dir;
					ny = 2;
				}
				else if (ny > c) {
					dir = 7 - dir;
					ny = c - 1;
				}
			}
		}

		fish[i].dir = dir;
		fish[i].x = nx;
		fish[i].y = ny;
		
		if (map[nx][ny] != 0) {
			if (fish[i].z > fish[map[nx][ny]].z) {
				fish[map[nx][ny]].status = 1;
				map[nx][ny] = i;
			}
			else {
				fish[i].status = 1;
			}
		}
		else {
			map[nx][ny] = i;
		}
	}
}
int main() {
	cin >> r >> c >> m;
	int a, b, s, d, z;
	Fish tmp(0,0,0,0,0,0);
	fish.push_back(tmp);
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> s >> d >> z;
		map[a][b] = i;
		Fish f(a,b,s,d,z,0);
		fish.push_back(f);
	}
	for (int p = 1; p <= c; p++) {
		fishing(p);
	}
	cout << answer << endl;
}