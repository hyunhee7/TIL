/*
	15:40 - 17:10
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int answer;

int dx[] = { 0,-1,1,0,0 }; //상 하 좌 우
int dy[] = { 0,0,0,-1,1 };
vector<int> map[101][101];

struct Node {
	int x;
	int y;
	int num;
	int dir;
};
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		n = 0, m = 0, k = 0;
		answer = 0;

		//입력
		cin >> n >> m >> k;
		vector<Node> cell(k);// x, y, num, dir
		for (int i = 0; i < k; i++) {
			cin >> cell[i].x >> cell[i].y >> cell[i].num >> cell[i].dir;
			map[cell[i].x][cell[i].y].push_back(i);
		}
		
		//시간흐름
		for (int time = 0; time < m; time++) {
			//1. 삭제
			for (int i = 0; i < k; i++) {
				if (cell[i].num == 0) continue;
				map[cell[i].x][cell[i].y].clear();
			}
			for (int i = 0; i < k; i++) {
				if (cell[i].num == 0)continue;
				cell[i].x += dx[cell[i].dir];
				cell[i].y += dy[cell[i].dir];
				map[cell[i].x][cell[i].y].push_back(i);
			}
			//2. 이동
			for (int i = 0; i < k; i++) {
				if (cell[i].num == 0)continue;
				if (cell[i].x == 0 || cell[i].x == n - 1 || cell[i].y == 0 || cell[i].y == n - 1) {
					cell[i].num = cell[i].num / 2;
					if (cell[i].dir == 1) 
						cell[i].dir = 2;
					else if (cell[i].dir == 2) 
						cell[i].dir = 1;
					else if (cell[i].dir == 3)
						cell[i].dir = 4;
					else 
						cell[i].dir = 3;
				}
				else if (map[cell[i].x][cell[i].y].size() > 1) {
					int sum = 0;
					int maxval = 0;
					int maxindex = 0;
					int x = cell[i].x;
					int y = cell[i].y;

					for (int i = 0; i < map[x][y].size(); i++) {
						sum += cell[map[x][y][i]].num;
						if (maxval < cell[map[x][y][i]].num) {
							maxval = cell[map[x][y][i]].num;
							maxindex = map[x][y][i];
						}
						cell[map[x][y][i]].num = 0;
					}
					cell[maxindex].num = sum;
				}
			}
		}

		//미생물 갯수 세기
		for (int i = 0; i < k; i++) {
			answer += cell[i].num;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j].clear();
			}
		}
		cout << "#" << t <<" " << answer<<endl;
	}
}