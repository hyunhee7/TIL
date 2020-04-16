/*
	15:30 - 17:00
*/
#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int map[10][10];
bool visited[10][10];
int answer = MAX;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dist[7][7];
bool selected[49];
bool connected[7][7];
bool isConn[7];
int totalNum = 0;
vector<pair<pair<int, int>, int>> load;
void bfs(int a, int b, int val) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	map[a][b] = val;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (map[nx][ny] == 1 && !visited[nx][ny]) {
				map[nx][ny] = val;
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}
void getDis(int rc, int r, int c) {
	//rc == 0 : 가로, rc == 1 : 세로
	if (rc == 0) {
		int d = 0;
		int fin = 0;
		for (int i = c + 1; i < m; i++) {
			
			if (map[r][i] > 0) {
				fin = map[r][i];
				break;
			}
			else {
				d++;
			}
		}
		if (fin && d >= 2) {
			if (dist[map[r][c]][fin] == 0) {
				dist[map[r][c]][fin] = d;
				dist[fin][map[r][c]] = d;
			}
			else {
				dist[map[r][c]][fin] = min(dist[map[r][c]][fin], d);
				dist[fin][map[r][c]] = min(dist[map[r][c]][fin], d);
			}
			
		}
	}
	else {
		int d = 0;
		int fin = 0;
		for (int i = r + 1; i < n; i++) {
			if (map[i][c] > 0) {
				fin = map[i][c];
				break;
			}
			else {
				d++;
			}
		}
		if (fin && d >= 2) {
			if (dist[map[r][c]][fin] == 0) {
				dist[map[r][c]][fin] = d;
				dist[fin][map[r][c]] = d;
			}
			else {
				dist[map[r][c]][fin] = min(dist[map[r][c]][fin], d);
				dist[fin][map[r][c]] = min(dist[map[r][c]][fin], d);
			}
		}
	}
}
bool getConnected() {
	memset(connected, 0, sizeof(connected));
	memset(isConn, 0, sizeof(isConn));

	bool flag = false;
	//선택된 연결 노드 표시
	for (int i = 0; i < load.size(); i++) {
		if (selected[i]) {
			int x = load[i].first.first;
			int y = load[i].first.second;
			connected[x][y] = true;
			connected[y][x] = true;
		}
	}
	//모두 연결되었는지 확인
	queue<int> q;
	q.push(1);
	isConn[1] = true;
	int connCnt = 1;
	while (!q.empty()) {
		if (connCnt == totalNum) {
			flag = true;
			break;
		}
		int val = q.front();
		q.pop();

		for (int i = 1; i <= totalNum; i++) {
			if (val == i)continue;
			if (connected[val][i] && !isConn[i]) {
				q.push(i);
				isConn[i] = true;
				connCnt++;
			}
		}
	}
	return flag;
}
void dfs(int index, int res, int cnt) {
	if (cnt >= 1) {
		if (getConnected() == true) {
			answer = min(res, answer);
		}
	}
	for (int i = index; i < load.size(); i++) {
		if (selected[i]) continue;
		selected[i] = true;
		dfs(i, res + load[i].second, cnt + 1);
		selected[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//1. 땅번호 붙이기
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				bfs(i, j, num);
				num++;
			}
		}
	}
	totalNum = num - 1;
	/*cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/
	//2. 연결 가능한 최소 다리길이 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0 && map[i][j + 1] == 0) {
				//가로 다리 놓기
				getDis(0, i, j);
			}
			if (map[i][j] > 0 && map[i + 1][j] == 0) {
				//세로 다리 놓기
				getDis(1, i, j);
			}
		}
	}
	/*for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}*/
	//3. i,j,dis 벡터
	for (int i = 1; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (dist[i][j] > 0) {
				load.push_back({ {i,j},dist[i][j] });
			}
		}
	}
	//4. 최종탐색할 수 있는 섬 갯수 파악
	dfs(0, 0, 0);
	
	if (answer == MAX) {
		answer = -1;
	}
	cout << answer << endl;
}