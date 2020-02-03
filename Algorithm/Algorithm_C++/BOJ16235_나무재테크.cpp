/*
	10:00-11:30
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int dy[] = { 0,0,1,-1,1,-1,-1,1 };
struct Tree {
	int x, y;
	int age;
};
int n, m, k, answer=0;
//priority_queue<Tree,vector<Tree>,cmp> pq;
//vector<Tree> list;
int a[11][11];   //겨울에 추가되는 양분
int now[11][11]; //현재 양분
vector<int> list[11][11];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//입력 및 초기화
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			now[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		Tree tree;
		cin >> tree.x >> tree.y >> tree.age;
		list[tree.x][tree.y].push_back(tree.age);
	}
	//시간 흐름
	for (int time = 0; time < k; time++) {
		//봄 - 나이만큼 양분을 먹는다.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int alive = 0;
				int die = 0;
				if (list[i][j].size() == 0) continue;
				vector<int> tmp;
				sort(list[i][j].begin(), list[i][j].end());
				for (int p = 0; p < list[i][j].size(); p++) {
					int age1 = list[i][j][p];
					if (list[i][j][p] <= now[i][j]) {
						now[i][j] -= list[i][j][p];
						tmp.push_back(age1 + 1);
					}
					else {
						die+=(age1/2);
					}
				}
				list[i][j].clear();
				for (int p = 0; p < tmp.size(); p++) {
					list[i][j].push_back(tmp[p]);
				}
				now[i][j] += die;
			}
		}
		//가을 - 나무가 번식한다
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int p = 0; p < list[i][j].size(); p++) {
					if (list[i][j][p] % 5 == 0) {
						for (int q = 0; q < 8; q++) {
							int nx = i + dx[q];
							int ny = j + dy[q];
							if (nx<1 || ny<1 || nx>n || ny>n) continue;
							list[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		//겨울 - 양분을 추가한다
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				now[i][j] += a[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			answer += list[i][j].size();
		}
	}
	cout << answer;
}