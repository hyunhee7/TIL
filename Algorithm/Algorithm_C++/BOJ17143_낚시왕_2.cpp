/*
	13:20 - 14:50 / 다시풀기
*/
#include <iostream>
#include <vector>
using namespace std;
struct Shark {
	int a, b;
	int s, d, z;
};
int map[101][101];
int r, c, m;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

int answer = 0;
int main() {
	cin >> r >> c >> m;
	vector<Shark> list(m+1);
	for (int i = 1; i <= m; i++) {
		cin >> list[i].a >> list[i].b >> list[i].s >> list[i].d >> list[i].z;
		map[list[i].a][list[i].b] = i;
	}
	int g = 0;
	for (int now = 1; now <= c; now++) {
		if (g == m) break;
		/*for (int i = 1; i <=r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "------" << endl;*/
		//1. 가까운 물고기 잡기
		for (int i = 1; i <= r; i++) {
			if (map[i][now] > 0) {
				answer+=list[map[i][now]].z;
				//cout << "ajrdma: " <<map[i][now]<< endl;
				list[map[i][now]].z = -1;
				map[i][now] = 0;
				g++;
				break;
			}
		}
		for (int i = 1; i < m + 1; i++) {
			map[list[i].a][list[i].b] = 0;
		}
		//2. 상어 이동
		for (int i = 1; i < m + 1; i++) {
			//cout << i << " " << list[i].z << endl;
			if (list[i].z < 0) continue;
			Shark shark = list[i];
			//이동
			int val, m;
			for (int t = 0; t < shark.s; t++) {
				if (shark.d == 1 || shark.d == 2) {
					int nx = shark.a + dx[shark.d];
					if (nx <= 0 || nx > r) {
						shark.d = 3 - shark.d;
					}
					shark.a += dx[shark.d];
				}
				else {
					int ny = shark.b + dy[shark.d];
					if (ny <= 0 || ny > c) {
						shark.d = 7 - shark.d;
					}
					shark.b += dy[shark.d];
				}
			}
			//map표시
			if (map[shark.a][shark.b] > 0) {
				if (list[map[shark.a][shark.b]].z < shark.z) {
					list[map[shark.a][shark.b]].z = -1;
					map[shark.a][shark.b] = i;
					list[i].a = shark.a;
					list[i].b = shark.b;
					list[i].d = shark.d;
				}
				else {
					list[i].z = -1;
				}
			}
			else {
				map[shark.a][shark.b] = i;
				list[i].a = shark.a;
				list[i].b = shark.b;
				list[i].d = shark.d;
			}
		}
	}
	cout << answer;
}
