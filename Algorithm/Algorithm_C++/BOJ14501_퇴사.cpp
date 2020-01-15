#include <iostream>
using namespace std;
int t[17];
int p[17];
int d[17];
int n, answer = 0;
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i + t[i] <= n+1) {
			d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
			answer = max(answer, d[i + t[i]]);
		}

		d[i + 1] = max(d[i + 1], d[i]);
		answer = max(answer, d[i+1]);
	}
	cout << answer;

}