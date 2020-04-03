#define MAX 987654321
#include<iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[11];
int n,m,temp;
int a[11];
int map[11][11];
int c[11];
int comp[11], visited[11];
int answer = MAX;
pair<int, int> dfs(int now, int value) {
	visited[now] = true;
	pair<int, int> ret = { 1,a[now] };
	for (int t : adj[now]) {
		if (comp[t] != value) continue;
		if (visited[t])continue;
		pair<int, int> _temp = dfs(t, value);
		ret.first += _temp.first;
		ret.second += _temp.second;
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}
	for (int i = 1; i < (1 << n) - 1; i++) { // 노드를 돈다.
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < n; j++) {		// 간선 존재 체크
			if (i & (1 << j)) {
				comp[j + 1] = 1;			//존재하면 idx1에 인덱스 넣기
				idx1 = j + 1;
			}
			else idx2 = j + 1;				//없으면 idx2에 넣기
		}
		pair<int, int> comp1 = dfs(idx1, 1); //idx1
		pair<int, int> comp2 = dfs(idx2, 0); //idx2
		if (comp1.first + comp2.first == n) answer = min(answer, abs(comp1.second - comp2.second));
	}
	if (answer == MAX) {
		answer = -1;
	}
	cout << answer << endl;
}