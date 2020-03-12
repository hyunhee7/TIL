/*
	11:30 - 13:00
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> die;
int answer = 0;
map<int, int> red = {
	{ 0, 2 },{ 2, 4 },{ 4, 6 },
	{ 6, 8 },{ 8, 10 },{ 10, 12 },
	{ 12, 14 },{ 14, 16 },{ 16, 18 },
	{ 18, 20 },{ 20, 22 },{ 22, 24 },
	{ 24, 26 },{ 26, 28 },{ 28, 30 },
	{ 30, 32 },{ 32, 34 },{ 34, 36 },
	{ 36, 38 },{ 38, 40 },{ 40, 50 }
};

map<int, int> blue = {
	{ 10, 13 },{ 13, 16 },{ 16, 19 },
	{ 19, 25 },{ 20, 22 },{ 22, 24 },
	{ 24, 25 },{ 30, 28 },{ 28, 27 },
	{ 27, 26 },{ 26, 25 },
};

map<int, int> blue_goal = {
	{ 25, 30 },{ 30, 35 },{ 35, 40 },{ 40, 50 }
};
int move(int idx, int mal, vector<pair<int, int>>& locate) {
	int present = locate[mal].first;
	int dir = locate[mal].second;
	int cnt = die[idx];
	if (present == 50) return 0;
	for (int j = 0; j < cnt; j++) {
		if (dir == 0)present = red[present];
		else if (dir == 1)present = blue[present];
		else if (dir == 2)present = blue_goal[present];
		if (present == 25)dir = 2;
		else if (present == 50)break;
	}
	if (present == 50) {
		locate[mal].first = present;
	}
	else {
		if (dir == 0 && (present == 10 || present == 20 || present == 30)) {
			dir = 1;
		}
		bool ok = true;
		for (int j = 0; j < 4; j++) {
			if (mal != j) {
				if (present == locate[j].first && (present == 40 || dir == locate[j].second)) {
					ok = false;
				}
			}
		}
		if (ok) {
			locate[mal].first = present;
			locate[mal].second = dir;
		}
		else {
			return -1;
		}
	}
	return 0;
}
void go(int idx, int sum, vector<pair<int, int>>& locate) {
	if (idx == 10) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int prev_locate = locate[i].first;
		int prev_dir = locate[i].second;

		int res = move(idx, i, locate);
		if (res > -1) {
			go(idx + 1, sum + res, locate);
		}
		locate[i].first = prev_locate;
		locate[i].second = prev_dir;
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		die.push_back(x);
	}
	vector<pair<int, int>> locate = {
		{0,0},
		{0,0},
		{0,0},
		{0,0}
	};
	go(0, 0, locate);
	cout << answer << endl;
}