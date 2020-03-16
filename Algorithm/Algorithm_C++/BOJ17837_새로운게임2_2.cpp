/*
	13:50 - 15:20
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
int map[13][13];
vector<int> mal[13][13];//index, dir
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
struct INFO {
	int index;
	int x, y;
	int dir;
};
vector<INFO> list;
bool isFin = false;
void blue(INFO info) {
	//방향 바꾸기
	if (list[info.index].dir == 1 || list[info.index].dir == 2) {
		list[info.index].dir = 3 - list[info.index].dir;
	}
	else {
		list[info.index].dir = 7 - list[info.index].dir;
	}
}
void white(INFO info, int nx ,int ny) {
	int x = info.x;
	int y = info.y;
	int index = info.index;
	int vsize = mal[x][y].size();
	vector<int> tmp;
	for (int i = vsize - 1; i >= 0; i--) {
		int now = mal[x][y][i];
		tmp.push_back(now);
		mal[x][y].pop_back();
		list[now].x = nx;
		list[now].y = ny;
		if (now == index) break;
	}
	for (int i = tmp.size()-1; i >= 0; i--) {
		mal[nx][ny].push_back(tmp[i]);
	}
}
void red(INFO info, int nx, int ny) {
	int x = info.x;
	int y = info.y;
	int index = info.index;
	int vsize = mal[x][y].size();
	vector<int> tmp;
	for (int i = vsize - 1; i >= 0; i--) {
		int now = mal[x][y][i];
		tmp.push_back(now);
		list[now].x = nx;
		list[now].y = ny;
		mal[x][y].pop_back();
		if (now == index) break;
	}
	for (int i = 0; i < tmp.size(); i++) {
		mal[nx][ny].push_back(tmp[i]);
	}
}
void move() {
	for (int i = 0; i < list.size(); i++) {
		INFO info = list[i];
		//cout << info.index << endl;
		int nx = info.x + dx[info.dir];
		int ny = info.y + dy[info.dir];
		//범위밖
		if (map[nx][ny] == 2 || nx <= 0 || nx > n || ny <= 0 || ny > n) {
			//방향 반대
			//cout << info.dir << ", " << "전 dir;" << nx << " " << ny << endl;
			blue(info);
			nx = info.x + dx[list[i].dir];
			ny = info.y + dy[list[i].dir];
			info.dir = list[i].dir;
			//cout << info.dir<<", "<<"dir;"<<nx << " " << ny << endl;
			if (map[nx][ny] == 2 || nx <= 0 || nx > n || ny <= 0 || ny > n) {
				//blue(info);
				//cout << "index: " << info.index << " " << nx << " " << ny << endl;
				continue;
			}else if(map[nx][ny]==0) white(info, nx, ny);
			else if(map[nx][ny]==1) red(info, nx, ny);
		}
		else if (map[nx][ny] == 0) {
			//cout << "이동:"<< nx << " " << ny << endl;
			white(info, nx, ny);
		}
		else if (map[nx][ny] == 1) {
			red(info, nx, ny);
		}

		//cout<<"size:" <<mal[nx][ny].size() << endl;
		//cout << "index: "<<info.index <<" "<< nx << " " << ny << endl;

		if (mal[nx][ny].size() >= 4) {
			isFin = true;
			return;
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int mal_num = 0;
	for (int i = 0; i < k; i++) {
		INFO info;
		cin >> info.x >> info.y >> info.dir;
		mal[info.x][info.y].push_back(i);
		info.index = i;
		list.push_back(info);
	}
	int answer = 1;
	while (answer < 1000) {
		//1. 모든 말 이동
		//cout << "time:" << answer << endl;
		move();
		//2. 
		if (isFin) break;
		answer++;
	}
	if (answer == 1000) {
		answer = -1;
	}
	cout << answer;
}