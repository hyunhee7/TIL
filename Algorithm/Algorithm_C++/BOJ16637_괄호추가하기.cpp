/*
	10:40 - 12:10
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
int answer = -987654321;
string line;
int calc(char opt, int val1, int val2) {
	int res = 0;

	if (opt == '+') {
		res = val1 + val2;
	}
	else if (opt == '-') {
		res = val1 - val2;
	}
	else {
		res = val1 * val2;
	}
	//cout << "res:" << res << endl;
	return res;
}
void dfs(int idx, int res) {
	if (idx == n) {
		if (res > answer) answer = res;
		return;
	}
	if (idx > n)return;
	//그냥 보내기
	int tmp = calc(line[idx], res, line[idx + 1] - '0');
	//cout << tmp <<endl;

	dfs(idx + 2, tmp);

	if (idx + 3 < n) {
		int val1 = line[idx + 1]-'0';
		int val2 = line[idx + 3]-'0';
		char opt = line[idx + 2];
		int val = calc(opt, val1, val2);
		int tmp2 = calc(line[idx], res, val);
		dfs(idx + 4, tmp2);
	}
}
int main() {
	cin >> n;
	cin >> line;
	int res = line[0]-'0';
	//cout << res << endl;
	dfs(1, res);
	cout << answer;
}