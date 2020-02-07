/*
	11:15 - 12:45
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int r, c, m;

struct Shark {
	int r, c;				//��ǥ
	int speed, dir, z;		//�ӵ�,����,ũ��
};
vector<Shark> map[101][101];
int now = 0;
int answer = 0;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
int main() {
	//�Է�
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++) {
		Shark shark;
		cin >> shark.r >> shark.c >> shark.speed >> shark.dir >> shark.z;
		map[shark.r][shark.c].push_back(shark);
	}

	for (int C = 0; C < c; C++) {
		//1. ���ÿ� �̵�
		now += 1;
		//2. �ش� �� ����� ��� ���
		for (int i = 1; i <= r; i++) {
			if (map[i][now].size()>0) {
				answer += map[i][now].front().z;
				//cout << map[i][now] << endl;
				map[i][now].clear();
				break;
			}
		}
		/*for (int i = 0; i < list.size(); i++) {
			cout << list[i].speed << " ";
		}
		cout << endl;*/
		//3. ��� �̵�
		//�ʱ�ȭ
		queue<Shark> q;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (map[i][j].size() > 0) {
					q.push(map[i][j][0]);
					map[i][j].clear();
				}
			}
		}
		while (!q.empty()) {
			Shark shark = q.front();
			int dir = shark.dir;
			int speed = shark.speed;
			int x = shark.r;
			int y = shark.c;
			int z = shark.z;
			q.pop();
			for (int i = 0; i < speed; i++) {
				//���� �ٲٱ�
				if (dir == 1 || dir == 2) {
					int nx = x + dx[dir];
					if (!(1 <= nx && nx <= r))
						dir = 3 - dir;
					x += dx[dir];
				}
				else {
					int ny = y + dy[dir];
					if (!(1 <= ny && ny <= c))
						dir = 7 - dir;
					y += dy[dir];
				}

				//�̵��ϱ�
				//cout << "��: " << shark.r << ", " << shark.c << endl;
				//cout << "��: " << shark.r << ", " << shark.c << endl;
			}
			shark.r = x;
			shark.c = y;
			shark.dir = dir;
			if (map[x][y].size()==0) {
				map[x][y].push_back(shark);
			}
			else {
				int val = map[x][y][0].z;
				if (val < z) {
					map[x][y].clear();
					map[x][y].push_back(shark);
				}
			}
		}
		//�̵�
		//��ħ ����
		/*cout << "------------" << endl;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << map[i][j].size() << ' ';
			}
			cout << endl;
		}*/
	}

	cout << answer << endl;
}