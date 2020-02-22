/*
	19:00 - 20:30 
	[틀린 코드]
	k의 범위가 최대 1000으로 나무 나이는 최대 1010 인데 그걸 고려하지 못함.
	나무의 최대 나이를 10으로 고정시켜서 예제는 모두 맞지만 히든케이스에서 틀림.
*/
#include <iostream>
#include <queue>
using namespace std;
int n, m, k;
int map[11][11];
int amap[11][11];
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int dy[] = { 0,0,1,-1,1,-1,-1,1 };
queue<pair<int, int>> q[1000];
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 5;
			cin >> amap[i][j];
		}
	}
	int a, b, age;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> age;
		q[age].push({ a,b });
	}
	while (k--) {
		//봄
		queue<pair<int, int>> tmpq[1000];
		queue<pair<int, int>> dieq[1000];
		for (int i = 1; i <= 1000; i++) {
			int size = q[i].size();
			while (size--) {
				int x = q[i].front().first;
				int y = q[i].front().second;
				q[i].pop();
				//양분 먹기
				if (map[x][y] >= i) {
					map[x][y] -= i;
					int age = i + 1;
					tmpq[age].push({ x,y });
				}
				//죽음
				else {
					int val = i / 2;
					dieq[val].push({ x,y });
				}
			}
		}
		//나이먹은 나무 넣기, 
		for (int i = 1; i <= 1000; i++) {
			int tmpsize = tmpq[i].size();
			for (int j = 0; j < tmpsize; j++) {
				int x = tmpq[i].front().first;
				int y = tmpq[i].front().second;
				q[i].push({ x,y });
				tmpq[i].pop();
			}
			while (!dieq[i].empty()) {
				int x = dieq[i].front().first;
				int y = dieq[i].front().second;
				map[x][y] += i;
				dieq[i].pop();
			}
		}
		//가을
		for (int i = 5; i <= 1000; i++) {
			if (i % 5 != 0)continue;
			int size = q[i].size();
			while (size--) {
				int x = q[i].front().first;
				int y = q[i].front().second;
				q[i].pop();
				for (int p = 0; p < 8; p++) {
					int nx = x + dx[p];
					int ny = y + dy[p];
					if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
					q[1].push({ nx,ny });
				}
				q[i].push({ x,y });
			}
		}
		//겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] += amap[i][j];
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= 10; i++) {
		answer += q[i].size();
	}
	cout << answer;
}