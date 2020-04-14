/*
	13:50 - 15:20
*/
#define MAX 987654321
#include <iostream>
#include <queue>
using namespace std;
int map[16][15];
int n, m, d;
int answer = 0;
void dfs(int index, int cnt) {
	if (cnt == 3) {
		//���� �� �� �̵�
		int tmap[16][15];
		queue<pair<int, int>> q;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				tmap[i][j] = map[i][j];
				if (map[i][j] == 1) {
					q.push({ i,j });
				}
			}
		}
		int enamyNum = q.size();
		int res = 0;
		while (enamyNum > 0) {
			for (int i = 0; i < m; i++) {
				if (tmap[n][i] == 2) {
					//2. ������ �� ���ϱ�
					int min_dis = MAX;
					int min_r = MAX;
					int min_c = MAX;
					for (int j = 0; j < enamyNum; j++) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						int dis = abs(n - x) + abs(i - y);
						
						if (dis <= d) {
							if (dis < min_dis) {
								min_dis = dis;
								min_r = x;
								min_c = y;
							}
							else if (dis == min_dis) {
								if (y < min_c) {
									min_dis = dis;
									min_r = x;
									min_c = y;
								}
							}
						}
						q.push({ x,y });
					}
					if (min_dis!=MAX) {
						tmap[min_r][min_c] = 0;
					}
				}
			}
			int qsize = q.size();
			//3. ���ݹ��� �� ���ֱ�
			for (int j = 0; j < qsize; j++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (tmap[x][y] != 0) {
					if (x + 1 < n) {
						q.push({ x + 1,y });
					}
					else enamyNum--;
				}
				else {
					enamyNum--;
					res++;
				}
			}
			//4. ���� �̵�
			for (int p = 0; p < n; p++) {
				for (int q = 0; q < m; q++) {
					tmap[p][q] = 0;
				}
			}
			qsize = q.size();
			for (int j = 0; j < qsize; j++) {
				int x = q.front().first;
				int y = q.front().second;
				tmap[x][y] = 1;
				q.pop();
				q.push({ x,y });
			}
		}
		//5. �ᱣ�� Ȯ��
		if (res > answer) {
			answer = res;
		}
		//3.���� maxval�� ��
		return;
	}
	if (index >= m) return;
	//�����ϱ�
	map[n][index] = 2;
	dfs(index + 1, cnt + 1);
	map[n][index] = 0;
	//���� ���ϱ�
	dfs(index + 1, cnt);
}
int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//1. �ü� �ڸ� ��ġ
	dfs(0,0);
	cout << answer << endl;
}