/*
	19:00 - 20:30 
	[Ʋ�� �ڵ�]
	k�� ������ �ִ� 1000���� ���� ���̴� �ִ� 1010 �ε� �װ� ������� ����.
	������ �ִ� ���̸� 10���� �������Ѽ� ������ ��� ������ �������̽����� Ʋ��.
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
		//��
		queue<pair<int, int>> tmpq[1000];
		queue<pair<int, int>> dieq[1000];
		for (int i = 1; i <= 1000; i++) {
			int size = q[i].size();
			while (size--) {
				int x = q[i].front().first;
				int y = q[i].front().second;
				q[i].pop();
				//��� �Ա�
				if (map[x][y] >= i) {
					map[x][y] -= i;
					int age = i + 1;
					tmpq[age].push({ x,y });
				}
				//����
				else {
					int val = i / 2;
					dieq[val].push({ x,y });
				}
			}
		}
		//���̸��� ���� �ֱ�, 
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
		//����
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
		//�ܿ�
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