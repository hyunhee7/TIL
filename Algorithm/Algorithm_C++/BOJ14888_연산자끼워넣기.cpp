/*
	시간초과
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
char num[101];
int opt[4];
int maxval = -1987654321;
int minval = 1987654321;
void dfs(int val, int optnum, vector<char> res) {

	if (optnum == n - 1 && val == n) {
		res.push_back(num[val]);

		vector<int> number;
		vector<char> operat;
		int answer = 0;
		for (int i = 0; i < res.size(); i++) {
			//cout << res[i] << ' ';
			if (i == 0 || i % 2 == 0) {
				number.push_back(res[i]-'0');
				
			}
			else {
				operat.push_back(res[i]);
			}
		}
		//cout << endl;
		answer += number[0];
		for (int i = 0; i < n - 1; i++) {
			if (operat[i] == '+') {
				answer += number[i + 1];
			}
			else if (operat[i] == '-') {
				answer -= number[i + 1];
			}
			else if (operat[i] == '*') {
				answer *= number[i + 1];
			}
			else {
				answer /= number[i + 1];
			}
		}
		if (answer > maxval)
			maxval = answer;
		if (answer < minval)
			minval = answer;
		return;
	}
	res.push_back(num[val]);
	//cout << num[val] << endl;
	for (int i = 0; i < 4; i++) {
		if (opt[i] > 0) {
			opt[i]--;

			if (i == 0)
				res.push_back('+');
			else if (i == 1)
				res.push_back('-');
			else if (i == 2)
				res.push_back('*');
			else
				res.push_back('/');

			dfs(val + 1, optnum + 1, res);

			res.pop_back();
			opt[i]++;
		}
	}
}
int main() {
	/*
	n개의 수
	n-1개의 연산자
	1,2,3,4,5,6
	+ 2 - 2 * 1 / 1
	총 60가지 식
	최대값, 최소값
	*/
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> opt[i];
	}
	vector<char> res;
	dfs(0, 0, res);
	//cout << "--------" << endl;
	cout << maxval<<endl;
	cout << minval;
}