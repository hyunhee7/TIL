#include <iostream>
#include <vector>
using namespace std;
int n;
int map[21][21];
bool team[21];
int answer = 987654321;
void dfs(int index, int cnt) {
	if (cnt == n / 2) {
		//점수계산
		int teamA = 0;
		int teamB = 0;
		//for (int i = 0; i < n; i++) {
		//	cout << team[i] << ' ';
		//}
		//cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (team[i] != team[j]) continue;
				if (team[i]==true && team[j]==true) {
					teamA += map[i][j];
				}
				else if (team[i] == false && team[j] == false) {
					teamB += map[i][j];
				}
			}
		}
		int res = abs(teamA - teamB);
		//cout << teamA << ' ' << teamB<<endl;
		if (answer > res) answer = res;
		return;
	}

	for (int i = index+1; i < n; i++) {
		team[i] = true;
		dfs(i, cnt + 1);
		team[i] = false;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		team[i] = true;
		dfs(i,1);
		team[i] = false;
	}
	cout << answer;
}