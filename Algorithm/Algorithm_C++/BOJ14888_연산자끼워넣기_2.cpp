#include <iostream>
#include <algorithm>
using namespace std;
int n;
int num[12];
int opt[4];
int maxval = -987654321;
int minval = 987654321;
void dfs(int plus, int minus, int mul, int div, int cnt, int res) {
	if (cnt == n) {
		maxval = max(maxval, res);
		minval = min(minval, res);
		return;
	}
	if (plus > 0) {
		dfs(plus - 1, minus, mul, div, cnt + 1, res + num[cnt]);
	}
	if (minus > 0) {
		dfs(plus, minus-1, mul, div, cnt + 1, res - num[cnt]);
	}
	if (mul > 0) {
		dfs(plus, minus, mul - 1, div, cnt + 1, res * num[cnt]);
	}
	if (div > 0) {
		dfs(plus, minus, mul, div - 1, cnt + 1, res / num[cnt]);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> opt[i];
	}
	dfs(opt[0], opt[1], opt[2], opt[3], 1, num[0]);
	cout << maxval << endl;
	cout << minval;
}