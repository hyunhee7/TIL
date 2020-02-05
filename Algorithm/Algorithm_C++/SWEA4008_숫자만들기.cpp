/*
	15:30-17:00
*/
#include <iostream>
using namespace std;
int n;
int p, minu, multiple, divide;
int number[13];
int maxval, minval;
void dfs(int a, int b, int c, int d, int val, int total) {
	if (val == n) {
		if (total > maxval) {
			maxval = total;
		}
		if (total < minval) {
			minval = total;
		}
		return;
	}

	if (a < p) {
		dfs(a + 1, b, c, d, val + 1, total + number[val]);
	}
	if (b < minu) {
		dfs(a, b + 1, c, d, val + 1, total - number[val]);
	}
	if (c < multiple) {
		dfs(a, b, c + 1, d, val + 1, total * number[val]);
	}
	if (d < divide) {
		dfs(a, b, c, d + 1, val + 1, total / number[val]);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {	
		maxval = -987654321;
		minval = 987654321;
		cin >> n;
		cin >> p >> minu >> multiple >> divide;
		for (int i = 0; i < n; i++) {
			cin >> number[i];
		}
		dfs(0, 0, 0, 0, 1, number[0]);
		int answer = maxval - minval;
		cout << "#" << t << " " << answer << endl;
	}
}