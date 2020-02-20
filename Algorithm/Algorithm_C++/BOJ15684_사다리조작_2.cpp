/*
	13:30 - 15:00
*/
#include <iostream>
using namespace std;
int n, h, m;
bool map[31][11];
bool mock[31][11];
bool isOK = false;
int answer = 0;
bool config() {
	if (isOK) return true;
	int count = 0;
	//cout << "--------" << endl;
	for (int j = 1; j <= n; j++) {
		int index = j;
		int res = 0;
		for (int i = 1; i <= h; i++) {
			if (map[i][index - 1] == 1 && index - 1 >= 1) {
				index -= 1;
			}
			else if (map[i][index] == 1 && index < n) {
				index += 1;

			}
			//cout << i << " " << index <<endl;
		}
		if (index == j) {
			count++;
		}
		//<<가지치기 하면 속도가 빨라진다!>>
		else
			return false;
	}
	//cout << "count: " <<count << endl;
	if (count == n)return true;
	else return false;
}
void dfs(int p, int cnt, int res) {
	if (isOK) return;
	if (cnt == res) {
		//cout << res << endl;
		isOK = config();
		return;
	}

	for (int i = p; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			//다리 놓기
			if (map[i][j] == 1) continue;
			if ((map[i][j - 1] == 1 && j > 1) || (map[i][j + 1] == 1 && j < n - 1)) continue;
			map[i][j] = 1;
			dfs(i, cnt + 1, res);
			if (isOK) return;
			map[i][j] = 0;
			
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	int res = 0;
	for (int i = 0; i <= 3; i++) {
		dfs(1, 0, i);
		if (isOK) { res = i; break; }
	}
	if (isOK) answer = res;
	else answer = -1;
	cout << answer;
}