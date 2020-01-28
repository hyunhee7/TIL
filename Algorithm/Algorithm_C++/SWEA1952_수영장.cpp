/*
	17:00 - 18:30
*/
#include <iostream>
using namespace std;
int cost[4];
int month[12];
bool visited[12];
int answer = 987654321;
void dfs(int total, int cnt) {
	if (cnt >= 12) {
		if (total < answer) {
			//cout << answer<<endl;
			answer = total;
		}
		return;
	}
	
	//1년권
	dfs(total + cost[3], cnt + 12);
	//3개월
	dfs(total + cost[2], cnt + 3);
	//1개월
	dfs(total + cost[1], cnt + 1);
	//1일
	dfs(total + (month[cnt] * cost[0]), cnt + 1);

}
int main() {
	int T=0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		fill(visited, visited + 12, false);
		answer = 987654321;
		//입력
		cin >> cost[0] >> cost[1] >> cost[2] >> cost[3];
		for (int i = 0; i < 12; i++) {
			cin >> month[i];
		}
		dfs(0,0);
		cout << "#" << t << " " << answer;
	}
}