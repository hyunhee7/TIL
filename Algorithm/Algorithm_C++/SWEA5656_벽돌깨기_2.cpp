/*
	14:45 - 16:15
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, w, h;
int map[15][12];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int answer;
void dfs(int index, int cnt, int (*nmap)[12]) {
	//4. n회가 끝나면 남은 벽돌 수를 체크한다.
	if (cnt == n) {
		int res = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (nmap[i][j] > 0) res++;
			}
		}
		
		if (res < answer)answer = res;
		return;
	}
	int tmap[15][12];
	bool visited[15][12];
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			tmap[i][j] = nmap[i][j];
		}
	}
	//2. 해당 index의 맨 위 벽돌부터 연속적으로 모두 깬다.
	int start = -1;
	//2-1. 맨 위 벽돌 찾기
	for (int i = 0; i < h; i++) {
		if (tmap[i][index] > 0) {
			start = i;
			break;
		}
	}
	if (start >= 0) {
		//2-2. 범위가 1인 경우
		if (tmap[start][index] == 1) {
			tmap[start][index] = 0;
		}
		//2-3. 범위가 1 이상인 경우
		else {
			queue<pair<int, int>> q;
			q.push({ start,index });
			visited[start][index] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				//범위 체크 및 벽돌 깨기(0 채우기)
				int d = tmap[x][y];
				tmap[x][y] = 0;
				for (int i = 0; i < 4; i++) {
					int nx = x;
					int ny = y;
					for (int j = 0; j < d - 1; j++) {
						nx += dx[i];
						ny += dy[i];
						if (nx < 0 || ny < 0 || nx >= h || ny >= w)break;
						//깨야할 범위가 추가되는 경우, 큐에 넣기
						if (tmap[nx][ny] > 1 && !visited[nx][ny]) {
							visited[nx][ny] = true;
							q.push({ nx,ny });
						}
						//범위가 1인 벽돌일 경우
						else if (tmap[nx][ny] == 1 && !visited[nx][ny]) {
							visited[nx][ny] = true;
							tmap[nx][ny] = 0;
						}
					}
				}
			}
			//3. 빈 공간 채우기
			for (int i = 0; i < w; i++) {
				queue<int> brick;
				for (int j = h - 1; j >= 0; j--) {
					if (tmap[j][i] > 0) {
						brick.push(tmap[j][i]);
						tmap[j][i] = 0;
					}
				}
				int idx = h - 1;
				while (!brick.empty()) {
					if (idx >= 0) {
						tmap[idx][i] = brick.front();
						brick.pop();
						idx--;
					}
				}
			}
		}
	}

	for (int i = 0; i < w; i++) {
		dfs(i, cnt + 1, tmap);
	}
}
int main() {
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> w >> h;
		answer = 987654321;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		//1. 구슬을 쏠 index(w, 가로값) 지정
		for (int i = 0; i < w; i++) {
			dfs(i, 0, map);
		}
		cout << "#" << t << " " << answer << endl;
	}
}