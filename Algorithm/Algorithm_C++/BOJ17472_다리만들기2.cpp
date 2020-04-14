/*
	14:45 - 16:15
*/
/*
예외case(https://www.acmicpc.net/board/view/41802)
ans:13

10 6
0 0 0 1 0 0
0 0 0 1 0 0
0 1 0 0 0 1
0 0 0 0 0 0
1 1 0 1 1 0
1 0 0 0 1 0
1 1 0 0 1 0
0 0 0 0 1 1
0 0 0 0 0 0
0 1 0 0 0 0
*/
#define MAX 987654321
#include <iostream>
#include <queue>
using namespace std;
int answer = MAX;
int n, m;
int map[11][11];
bool visited[11][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dist[7][7];
int dvisited[7];
void bfs(int a, int b, int val) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	map[a][b] = val;
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!visited[nx][ny] && map[nx][ny]) {
				visited[nx][ny] = true;
				map[nx][ny] = val;
				q.push({ nx,ny });
			}
		}
	}
}
void dfs(int index, int cnt, int dnum, int res) {
	if (cnt == dnum - 1) {
		//cout << cnt << endl;
		answer = min(res, answer);
		for (int i = 1; i < dnum; i++) {
			cout << dvisited[i] << ' ';
		}
		cout << endl;
		return;
	}
	//if (res > answer) return;
	//if (cnt > dnum)return;
	dvisited[index] = true;

	for (int i = 1; i < dnum; i++) {
		
		if (i == index) continue;
		if (dist[index][i] > 0 && !dvisited[i]) {
			
			dvisited[i] = true;
			cout << "indx:" << index << ",i :"<<i << ", dst:" << dist[index][i] <<", res:"<<res+dist[index][i] << endl;
			//cout << i << endl;
			cout << "cnt:"<<cnt << endl;
			dfs(index, cnt + 1, dnum, res + dist[index][i]);
			dfs(i, cnt + 1, dnum, res + dist[index][i]);
			dvisited[i] = false;
		}
	}
	//dvisited[index] = false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//땅번호 표시
	int d[7];
	int dnum = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]==1 && !visited[i][j]) {
				bfs(i, j, dnum);
				dnum++;
			}
			
		}
	}
	cout << "------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	//다리놓기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0 && j+1<m && map[i][j+1]==0) {//가로 다리놓기
				for (int k = j + 1; k < m; k++) {
					if (map[i][k] > 0) {
						int idx1 = map[i][j];
						int idx2 = map[i][k];
						int val = k - j - 1;
						if (val <= 1) break;
						//cout << idx1 << " " << idx2 << " " << val << endl;
						//cout << "i,j :" << i << ", " << j << ", [k,j] : " << k << " " << j << endl;
						if (dist[idx1][idx2] > 0) {
							dist[idx1][idx2] = min(val, dist[idx1][idx2]);
							dist[idx2][idx1] = min(val, dist[idx2][idx1]);
						}
						else {
							dist[idx1][idx2] = val;
							dist[idx2][idx1] = val;
						}
						break;
					}
				}
			}
			if (map[i][j] > 0 && i+1<n && map[i + 1][j] == 0) {//세로 다리놓기
				for (int k = i + 1; k < n; k++) {
					if (map[k][j] > 0) {
						//cout << "dddd:" <<map[k][j] << endl;
						int idx1 = map[i][j];
						int idx2 = map[k][j];
						//cout << "i:" << i << ", k:" << k <<",j:"<<j << endl;
						int val = k - i - 1;
						//cout << "val:" << val<<endl;
						if (val <= 1)break;
						//cout << idx1 << " " << idx2 << " " << val << endl;
						//cout << "i,j :" << i << ", " << j << ", [k,j] : " << k << " " << j << endl;
						if (dist[idx1][idx2] > 0) {
							dist[idx1][idx2] = min(val, dist[idx1][idx2]);
							dist[idx2][idx1] = min(val, dist[idx2][idx1]);
						}
						else {
							dist[idx1][idx2] = val;
							dist[idx2][idx1] = val;
						}
						break;
					}
				}
			}
		}
	}
	//최단거리 구하기
	//dfs(1,1,dnum, 0);
	dfs(1, 1, dnum, 0);
	cout << "------" << endl;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	if (answer == MAX) answer = -1;
	cout << answer << endl;
}