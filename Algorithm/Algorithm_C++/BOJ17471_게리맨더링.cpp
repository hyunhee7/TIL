/*
	10:00 - 11:30
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
int total = 0;
int p[11];
int map[11][11];
bool visited[11];
int answer = 987654321;
void dfs(int index, int num, int cnt) {
	if (cnt >= n) return;

	//BÆÀ Ã£±â
	queue<int> q;
	int c[11];
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			c[i] = 1;
			q.push(i);
		}
	}

	int val = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (map[a][i] && c[i]) {
				val++;
				break;
			}
		}
	}
	if (val + cnt == n) {
		int tmp = total - num;
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ';
		}
		cout << endl;
		cout << num << " " << tmp << ", answer: "<<abs(num-tmp)<< endl;
		if (abs(num - tmp) < answer)answer = abs(num - tmp);
	}
	//°è»ê
	for (int i = 1; i <= n; i++) {
		if (map[index][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, num + p[i], cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		total += p[i];
	}
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int tmp;
			cin >> tmp;
			map[i][tmp] = 1;
			map[tmp][i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		dfs(i, p[i], 1);
		visited[i] = false;
	}
	if (answer == 987654321) answer = -1;
	cout << answer << endl;
}