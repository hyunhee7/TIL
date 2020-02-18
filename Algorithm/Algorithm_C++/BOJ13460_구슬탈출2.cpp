#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define SIZE 12
int N, M;
char map[SIZE][SIZE];
struct point {
	int rx, ry, bx, by;
};
queue<point>que;
int cnt;
int rx, ry, bx, by;
int nrx, nry, nbx, nby;
int orx, ory, obx, oby;
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visit[SIZE][SIZE][SIZE][SIZE];

void problemIn() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				bx = i;
				by = j;
				map[i][j] = '.';
			}
		}
	}
}
void bfs() {
	while (!que.empty()) {
		int qlen = que.size();
		while (qlen--) {
			orx = que.front().rx;
			ory = que.front().ry;
			obx = que.front().bx;
			oby = que.front().by;
			que.pop();
			if (map[orx][ory] == 'O' && map[obx][oby] != 'O') {
				ans = cnt;
				return;
			}
			for (int i = 0; i < 4; i++) {
				rx = orx;
				ry = ory;
				bx = obx;
				by = oby;
				//빨간구슬
				while (1) {
					nrx = rx + dx[i];
					nry = ry + dy[i];
					if (map[nrx][nry] == '#' || map[rx][ry] == 'O') break;
					rx = nrx;
					ry = nry;
				}
				//파란구슬
				while (1) {
					nbx = bx + dx[i];
					nby = by + dy[i];
					if (map[nbx][nby] == '#' || map[rx][ry] == 'O')break;
					bx = nbx;
					by = nby;
				}
				if (rx == bx && ry == by) {
					if (map[bx][by] == 'O') continue;
					if (abs(orx - rx) + abs(ory - ry) > abs(obx - bx) + abs(oby - by)) {
						rx -= dx[i];
						ry -= dy[i];
					}
					else {
						bx -= dx[i];
						by -= dy[i];
					}
				}
				if (visit[rx][ry][bx][by]) continue;
				visit[rx][ry][bx][by] = 1;
				que.push({ rx,ry,bx,by });
			}
		}
		if (cnt == 10) {
			ans = -1;
			return;
		}
		cnt++;
	}
	ans = -1;
	return;
}
void solve() {
	visit[rx][ry][bx][by] = 1;
	que.push({ rx,ry,bx,by });
	bfs();
}
int main() {
	problemIn();
	solve();
	cout << ans << endl;
}