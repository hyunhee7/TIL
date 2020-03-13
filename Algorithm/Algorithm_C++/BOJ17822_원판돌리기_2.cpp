/*
	11:30 - 13:00
*/
#include <iostream>
#include <queue>
using namespace std;
int n, m, t;
int map[51][51];
int order[51][3];
bool visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void rotate(int j, int d, int k) {
	//j번째, dir, 칸수
	//cout << j << endl;
	if (d == 0) { //시계
		for (int p = 0; p < k; p++) {
			int last = map[j][m - 1];
			for (int i = m - 1; i >= 1; i--) {
				map[j][i] = map[j][i - 1];
			}
			map[j][0] = last;
		}
	}
	else { //반시계
		for (int p = 0; p < k; p++) {
			int first = map[j][0];
			for (int i = 0; i < m - 1; i++) {
				map[j][i] = map[j][i + 1];
			}
			map[j][m - 1] = first;
		}
	}
}
int bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	int cnt = 0;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n) continue;
			if (ny < 0) {
				ny = m - 1;
			}
			else if (ny >= m) {
				ny = 0;
			}
			if (!visited[nx][ny] && map[nx][ny] == map[a][b] && map[nx][ny]>0) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				map[nx][ny] = -1;
				cnt++;
			}
		}
	}
	if (cnt > 0) {
		//cout << "change: " << a << " " << b << endl;
		map[a][b] = -1;
		return 1;
	}
	else return 0;
}
void del() {
	//인접칸 지우기
	int isOK = 0;
	float total = 0;
	float val = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) isOK+=bfs(i, j);
			if (map[i][j] > 0) {
				total += map[i][j];
				val++;
			}
		}
	}
	//cout << "isOK:" << isOK << endl;
	if (isOK == 0) {
		float avg = total / val;
		//cout << "avg:" << avg << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				float value = map[i][j];
				if (value > avg) map[i][j] -= 1;
				if (value < avg && map[i][j]>0) map[i][j] += 1;
			}
		}
	}
}
int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		order[i][0] = x;
		order[i][1] = d;
		order[i][2] = k;
	}
	for (int i = 0; i < t; i++) {
		//x배수 d방향 k칸 회전
		int x = order[i][0];
		int d = order[i][1];
		int k = order[i][2];
		for (int j = 0; j < n; j++) {
			int v = j + 1;
			//cout << "x:" << x << endl;
			if (v % x == 0) rotate(j, d, k);
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "-------" << endl;*/
		for (int p = 0; p < n; p++) {
			for (int q = 0; q < m; q++) {
				visited[p][q] = false;
			}
		}
		del();
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) answer += map[i][j];
			//cout << map[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << answer << endl;
}