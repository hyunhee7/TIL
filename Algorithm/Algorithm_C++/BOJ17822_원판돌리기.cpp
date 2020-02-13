/*
	13:05 - 14:35
*/
#include <iostream>
#include <queue>
using namespace std;
int n, m, t;
int map[51][51];
int T[51][3];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void rotating(int index, int dir, int k) {
	//index�� dir�������� kĭ ȸ��
	//�ð�
	for (int K = 0; K < k; K++) {
		if (dir == 0) {
			int last = map[index][m];
			for (int i = m; i > 1; i--) {
				map[index][i] = map[index][i - 1];
			}
			map[index][1] = last;
		}
		//�ݽð�
		else {
			int first = map[index][1];
			for (int i = 1; i < m; i++) {
				map[index][i] = map[index][i + 1];
			}
			map[index][m] = first;
		}
	}
}
int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < t; i++) {
		//x�ǹ�� ����, ����, ȸ�� ĭ��
		cin >> T[i][0] >> T[i][1] >> T[i][2];
	}
	for (int time = 0; time < t; time++) {
		//cout << "T:" << time << endl;
		int x = T[time][0];
		int dir = T[time][1];//0�ð� 1�ݽð�
		int k = T[time][2]; //ĭ
		//1. x��� ���� ã��
		for (int i = 1; i <= n; i++) {
			
			if (i % x != 0) continue;
			//d�������� kĭ ȸ��
			//cout << "���: " << i << " " << x << endl;
			rotating(i,dir,k);

		}
		/*cout << "----" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}*/
		//2.������ ���� �� ó��
		bool isAvg = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == -1) continue;
				//cout << "i,j: "<<i << " " << j << endl;
				bool visited[51][51];
				for (int p = 1; p <= n; p++) {
					for (int q = 1; q <= m; q++) {
						visited[p][q] = false;
					}
				}
				int cnt = 0;
				queue<pair<int,int>> q;
				q.push(make_pair(i, j));
				int val = map[i][j];
				//cout <<"val:"<< val << endl;
				//visited[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					visited[x][y] = true;
					//cout << "x,y: " << x << " " << y << endl;
					for (int d = 0; d < 4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];
						//cout << "nx,ny:" << nx << " " << ny << endl;
						if (nx < 1 || nx > n) continue;
						if (ny < 1) {
							ny = m;
						}
						else if (ny > m) {
							ny = 1;
						}
						//cout << "nx,ny2:" << nx << " " << ny << endl;
						//cout << "����: "<<visited[nx][ny] << " " << map[nx][ny] << endl;
						if (visited[nx][ny] == true || map[nx][ny] == -1) continue;
						if (map[nx][ny] == val) {
							q.push(make_pair(nx, ny));
							cnt++;
							//visited[nx][ny] = true;
							isAvg = false;
							map[nx][ny] = -1;
						}
					}
				}
				if (cnt > 0) {
					map[i][j] = -1;
				}
				//cout << "----" << endl;
				/*for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						cout << map[i][j] << ' ';
					}
					cout << endl;
				}*/
			}
		}
		//3. ������ ���
		if (isAvg) {
			float total = 0, count = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j] > 0) {
						total += map[i][j];
						count++;
					}
				}
			}
			float avg = total / count;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j] <= 0) continue;
					if (map[i][j] > avg) {
						map[i][j] -= 1;
					}
					else if (map[i][j] < avg)
						map[i][j] += 1;
				}
			}
		}
		/*cout << "avg----" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/
	}
	//cout << "--" << endl;
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//cout << map[i][j] << ' ';
			if (map[i][j] > 0) {
				answer += map[i][j];
			}
		}
		//cout << endl;
	}
	cout << answer;
}