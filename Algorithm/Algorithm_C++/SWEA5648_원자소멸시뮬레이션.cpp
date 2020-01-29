/*
	13:10 - 14:40
*/
#include <iostream>
#include <vector>
using namespace std;
int n, answer;
int map[4001][4001];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
struct Node {
	int x, y;
	int dir;
	int k;
	int index;
	bool survive;
};
Node info[1001];
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		n = 0;
		answer = 0;
		for (int i = 0; i < 4001; i++) {
			for (int j = 0; j < 4001; j++) {
				map[i][j] = 0;
			}
		}
		//입력
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y, dir, k;
			cin >> y >> x >> dir >> k;
			Node node;
			node.x = (2*x)+2000; node.y = (2*y)+2000;
			//cout << "x: "<<node.x << ", y:" << node.y << endl;
			node.dir = dir; node.k = k; 
			node.index = i;
			node.survive = true;
			info[i] = node;
			map[node.x][node.y]++;
		}
		for (int time = 0; time < 4002; time++) {
			//삭제
			for (int i = 0; i < n; i++) {
				if (map[info[i].x][info[i].y] > 0) {
					map[info[i].x][info[i].y] = 0;
				}
			}
			//원자 이동
			for (int i = 0; i < n; i++) {
				if (!info[i].survive) continue;
				int dir = info[i].dir;
				int nx = info[i].x + dx[dir];
				int ny = info[i].y + dy[dir];
				if (nx < 0 || ny < 0 || nx>4000 || ny>4000) continue;
				info[i].x = nx;
				info[i].y = ny;
				map[info[i].x][info[i].y]++;
			}
			//충돌 확인
			for (int i = 0; i < n; i++) {
				if (!info[i].survive) continue;
				if (map[info[i].x][info[i].y] > 1) {
					answer += info[i].k;
					info[i].survive = false;
					for (int j = i+1; j < n; j++) {
						if (info[j].x == info[i].x && info[j].y == info[i].y) {
							answer += info[j].k;
							info[j].survive = false;
						}

					}
				}
			}
		}
		/*cout << "-------" <<endl;
		cout << info[0].x << " " << info[0].y << " " << info[0].survive << endl;
		cout << info[1].x << " " << info[1].y << " " << info[1].survive << endl;

		cout << info[2].x << " " << info[2].y<<" "<<info[2].survive << endl;
		cout << info[3].x << " " << info[3].y << " " << info[2].survive << endl;*/

		cout << "#" << t << " " << answer << endl;
	}

}