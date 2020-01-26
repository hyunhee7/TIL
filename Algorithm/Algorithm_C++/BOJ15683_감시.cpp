/*
	14:10 - 15:40
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[9][9];
int answer = 987654321;
vector<pair<int, int>> cctv;
bool visited[9][9];
void goEast(int x, int y) {
	for (int p = y; p < m; p++) {
		if (map[x][p] == 6) break;
		visited[x][p] = true;
	}
}
void goWest(int x, int y) {
	for (int p = y; p >= 0; p--) {
		if (map[x][p] == 6) break;
		visited[x][p] = true;
	}
}
void goNorth(int x, int y) {
	for (int p = x; p >= 0; p--) {
		if (map[p][y] == 6) break;
		visited[p][y] = true;
	}
}
void goSouth(int x, int y) {
	for (int p = x; p < n; p++) {
		if (map[p][y] == 6) break;
		visited[p][y] = true;
	}
}
void dfs(int cnt, vector<int> dir) {
	if (cnt == cctv.size()) {

		for (int i = 0; i < n; i++) {
			fill(visited[i], visited[i] + m, false);
		}
		//visited�� ǥ��
		for (int i = 0; i < cctv.size(); i++) {
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (map[x][y] == 1) {
				//��
				if (dir[i] == 0) {
					goEast(x, y);
				}
				//��
				else if (dir[i] == 1) {
					goWest(x, y);
				}
				//��
				else if (dir[i] == 2) {
					goNorth(x, y);
				}
				//��
				else {
					goSouth(x, y);
				}
			}
			else if (map[x][y] == 2) {
				if (dir[i] == 0) {
					goEast(x, y);
					goWest(x, y);
				}
				else {
					goNorth(x, y);
					goSouth(x, y);
				}
			}
			else if (map[x][y] == 3) {
				//��
				if (dir[i] == 0) {
					goNorth(x, y);
					goEast(x, y);
				}
				//��
				else if (dir[i] == 1) {
					goEast(x, y);
					goSouth(x, y);
				}
				//��
				else if (dir[i] == 2) {
					goSouth(x, y);
					goWest(x, y);
				}
				//��
				else {
					goWest(x, y);
					goNorth(x, y);
				}
			}
			else if (map[x][y] == 4) {
				//��
				if (dir[i] == 0) {
					goWest(x, y);
					goNorth(x, y);
					goEast(x, y);
				}
				//��
				else if (dir[i] == 1) {
					goNorth(x, y);
					goEast(x, y);
					goSouth(x, y);
				}
				//��
				else if (dir[i] == 2) {
					goEast(x, y);
					goSouth(x, y);
					goWest(x, y);
				}
				//��
				else {
					goSouth(x, y);
					goWest(x, y);
					goNorth(x, y);
				}
			}
			else {
				goNorth(x, y);
				goEast(x, y);
				goSouth(x, y);
				goWest(x, y);
			}
		}
		int res = 0;
		//false���� üũ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//cout << visited[i][j] << ' ';
				if (!visited[i][j] && map[i][j]==0) res++;
			}
			//cout << endl;
		}
		//cout << "---------"<<endl;
		//res<min?
		if (res < answer)
			answer = res;
		return;
	}
	//1,3,4 �϶� 0-3 ���� 
	int x = cctv[cnt].first;
	int y = cctv[cnt].second;
	//���� ����
	if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4) {
		for (int i = 0; i < 4; i++) {
			dir.push_back(i);
			dfs(cnt + 1, dir);
			dir.pop_back();
		}
	}
	else if (map[x][y] == 2) {
		for (int i = 0; i < 2; i++) {
			dir.push_back(i);
			dfs(cnt + 1, dir);
			dir.pop_back();
		}
	}
	else {
		dir.push_back(0);
		dfs(cnt + 1, dir);
		dir.pop_back();
	}
}
int main() {
	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	//cctv���� ����
	vector<int> dir;
	dfs(0,dir);
	cout << answer;
}