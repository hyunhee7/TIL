/*
	20:00 - 21:30
*/
#include <iostream>
#include <vector>
using namespace std;
int map[10][10];
bool visited[10][10];
vector<pair<int, int>> info;
int val = 0;
bool onef(int x, int y) {
	if (!visited[x][y]) {
		visited[x][y] = true;
		return true;
	}
	return false;
}
bool twof(int x, int y) {
	if (!visited[x][y] && !visited[x][y + 1] && map[x][y + 1] == 1
		&& !visited[x + 1][y] && map[x + 1][y] == 1 &&
		!visited[x + 1][y + 1] && map[x + 1][y + 1] == 1) {
		return true;
	}
	return false;
}
bool threef(int x, int y) {
	if (!visited[x][y] 
		&& !visited[x][y + 1] && map[x][y + 1] == 1
		&& !visited[x][y + 2] && map[x][y + 2] == 1
		&& !visited[x + 1][y] && map[x + 1][y] == 1
		&& !visited[x + 2][y] && map[x + 2][y] == 1
		&& !visited[x + 1][y + 1] && map[x + 1][y + 1] == 1
		&& !visited[x + 2][y + 2] && map[x + 2][y + 2] == 1) {
		return true;
	}
	return false;
}
bool fourf(int x, int y) {
	if (!visited[x][y]
		&& !visited[x][y + 1] && map[x][y + 1] == 1
		&& !visited[x][y + 2] && map[x][y + 2] == 1
		&& !visited[x][y + 3] && map[x][y + 3] == 1
		&& !visited[x + 1][y] && map[x + 1][y] == 1
		&& !visited[x + 2][y] && map[x + 2][y] == 1
		&& !visited[x + 3][y] && map[x + 3][y] == 1
		&& !visited[x + 1][y + 1] && map[x + 1][y + 1] == 1
		&& !visited[x + 2][y + 2] && map[x + 2][y + 2] == 1
		&& !visited[x + 3][y + 3] && map[x + 3][y + 3] == 1) {
		return true;
	}
	return false;
}
bool fivef(int x, int y) {
	if (!visited[x][y]
		&& !visited[x][y + 1] && map[x][y + 1] == 1
		&& !visited[x][y + 2] && map[x][y + 2] == 1
		&& !visited[x][y + 3] && map[x][y + 3] == 1
		&& !visited[x][y + 4] && map[x][y + 4] == 1
		&& !visited[x + 1][y] && map[x + 1][y] == 1
		&& !visited[x + 2][y] && map[x + 2][y] == 1
		&& !visited[x + 3][y] && map[x + 3][y] == 1
		&& !visited[x + 4][y] && map[x + 4][y] == 1
		&& !visited[x + 1][y + 1] && map[x + 1][y + 1] == 1
		&& !visited[x + 2][y + 2] && map[x + 2][y + 2] == 1
		&& !visited[x + 3][y + 3] && map[x + 3][y + 3] == 1
		&& !visited[x + 4][y + 4] && map[x + 4][y + 4] == 1) {
		return true;
	}
	return false;
}
void dfs(int one, int two, int three, int four, int five) {
	if (one == 5 && two == 5 && three == 5 && four == 5 && five == 5) {
		
		return;
	}
	for (int i = 0; i < info.size(); i++) {
		if (!visited[info[i].first][info[i].second]) {
			bool tmp1 = onef(info[i].first,info[i].second);
			if (tmp1) {
				dfs(one + 1, two, three, four, five);
			}
			else return;
			bool tmp2 = twof(info[i].first, info[i].second);
			if (tmp2) {
				dfs(one, two + 1, three, four, five);
			}
			else return;
			bool tmp3 = threef(info[i].first, info[i].second);
			if (tmp3) {
				dfs(one, two, three + 1, four, five);
			}
			else return;
			bool tmp4 = fourf(info[i].first, info[i].second);
			if (tmp4) {
				dfs(one, two, three, four + 1, five);
			}
			else return;
			bool tmp5 = fivef(info[i].first, info[i].second);
			if (tmp5) {
				dfs(one, two, three, four, five + 1);
			}
			else return;
			return;
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				info.push_back({ i,j });
			}
		}
	}
	dfs(0, 0, 0, 0, 0);
}