/*
	14:00 - 15:30
*/
#include <iostream>
using namespace std;
int n, m;
bool checked[9];
int res[9];
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!checked[i]) {
			res[cnt] = i;
			checked[i] = true;
			dfs(cnt + 1);
			checked[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	dfs(0);
}