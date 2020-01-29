/*
	16:00-17:30
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int map[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int answer = 987654321;
void dfs(vector<int> choice, int num, int cnt, int m) {
	if (cnt > chicken.size()) return;
	if (num == m) {
		//거리측정
		int total = 0;
		for (int i = 0; i < house.size(); i++) {
			int minval = 9876543421;
			for (int j = 0; j < choice.size(); j++) {
				int tmp = abs(house[i].first - chicken[choice[j]].first) + abs(house[i].second - chicken[choice[j]].second);
				if (minval > tmp) minval = tmp;
			}
			total += minval;
		}
		//min?
		if (total < answer) answer = total;
		return;
	}
	dfs(choice,num,cnt+1,m);
	choice.push_back(cnt);
	dfs(choice,num+1,cnt+1,m);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> choice;
	dfs(choice, 0, 0, m);
	cout << answer;
}