/*
	14:00 - 15:30
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int answer = 0;
int n, m, d;
int map[16][16];
int tmp[16][16];
int attacker[16];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void attack(queue<pair<int,int>> q, int a) {
	int minval = 987654321;
	int min_x = 987654321; int min_y = 987654321;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int dis = abs(x - (n + 1)) + abs(y - a);
		if (dis <= d) {
			if (dis < minval) {
				min_x = x;
				min_y = y;
				minval = dis;
			}
			else if (dis == minval) {
				if (x < min_x) {
					min_x = x;
					min_y = y;
					minval = dis;
				}
			}
		}
		
	}
	if (min_x == 987654321 || min_y == 987654321) return;
	tmp[min_x][min_y] = 2;
	cout << min_x << " " << min_y << endl;
	return;

}
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		//cout << "------" << endl;
		queue<pair<int, int>> enamy;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				tmp[i][j] = map[i][j];
				if (map[i][j] == 1)enamy.push({ i,j });
			}
		}
		int res = 0;
		bool isFin = false;
		
		while (!isFin) {
			//공격
			for (int i = 1; i <= m; i++) {
				if (attacker[i]) {
					attack(enamy, i);
				}
			}
			/*cout << "////////////" << endl;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					cout << tmp[i][j] << ' ';
				}
				cout << endl;
			}*/

			while (!enamy.empty()) {
				enamy.pop();
			}
			//공격받은 적들 제외 및 res+=res;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (tmp[i][j] == 2) {
						//cout << i << " " << j << endl;
						res++;
						tmp[i][j] = 0;
					}
					else if (tmp[i][j] == 1) {
						tmp[i][j] = 0;
						enamy.push({ i,j });
					}
				}
			}
			//이동
			int qsize = enamy.size();
			for (int i = 0; i < qsize; i++) {
				int x = enamy.front().first;
				int y = enamy.front().second;
				enamy.pop();
				if (x + 1 <= n) {
					tmp[x + 1][y] = 1;
					enamy.push({ x + 1,y });
				}
			}
			//적의 수 0이면 종료
			if (enamy.size()<=0) isFin = true;
			
		}
		
		if (res > answer)answer = res;

		return;
	}
	if (idx > m)return;
	attacker[idx] = true;
	dfs(idx + 1, cnt + 1);
	attacker[idx] = false;
	dfs(idx + 1, cnt);
}
int main() {
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	dfs(1, 0);
	cout << answer;
}