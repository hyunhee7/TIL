/*
	17:30 - 19:00
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int m, a, answer;
int a_list[101];
int b_list[101];
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,1,0,-1};

struct BC {
	int x, y;
	int range;
	int power;
};
vector<BC> bc_list;
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		m = 0, a = 0;
		fill(a_list, a_list + 101, 0);
		fill(b_list, b_list + 101, 0);
		bc_list.clear();
		answer = 0;
		//입력
		cin >> m >> a;
		for (int i = 0; i < m; i++) {
			cin >> a_list[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b_list[i];
		}
		for (int i = 0; i < a; i++) {
			BC bc;
			cin >> bc.y >> bc.x >> bc.range >> bc.power;
			bc_list.push_back(bc);
		}
		int ax = 1, ay = 1;
		int bx = 10, by = 10;
		for (int time = 0; time <= m; time++) {
			//범위 계산
			vector<int> a_index;
			vector<int> b_index;
			for (int i = 0; i < a; i++) {
				int bc_x = bc_list[i].x;
				int bc_y = bc_list[i].y;
				int bc_range = bc_list[i].range;
				//a
				int len_a = abs(ax - bc_x) + abs(ay - bc_y);
				//b
				int len_b = abs(bx - bc_x) + abs(by - bc_y);
				//범위 포함인지
				if (len_a <= bc_range) a_index.push_back(i);
				if (len_b <= bc_range) b_index.push_back(i);
			}
			//충전 계산
			if (a_index.size() == 0 && b_index.size() == 0) {
				answer += 0;
			}
			else if (a_index.size() >= 1 && b_index.size() == 0) {
				int maxval = 0;
				for (int i = 0; i < a_index.size(); i++) {
					if (bc_list[a_index[i]].power > maxval)
						maxval = bc_list[a_index[i]].power;
				}
				answer += maxval;
			}
			else if (a_index.size() == 0 && b_index.size() >= 1) {
				int maxval = 0;
				for (int i = 0; i < b_index.size(); i++) {
					if (bc_list[b_index[i]].power > maxval)
						maxval = bc_list[b_index[i]].power;
				}
				answer += maxval;
			}
			else {
				//cout << a_index.size() << " " << b_index.size() << endl;
				int maxval = 0;
				for (int i = 0; i < a_index.size(); i++) {
					for (int j = 0; j < b_index.size(); j++) {
						int val = 0;
						if (a_index[i] == b_index[j]) {
							val += bc_list[a_index[i]].power;
						}
						else {
							val += bc_list[a_index[i]].power;
							val += bc_list[b_index[j]].power;
						}
						if (val > maxval) maxval = val;
					}
				}
				//cout <<"max: "<< maxval<<endl;
				answer += maxval;
			}
			//cout << "t: "<< time<<", answer: "<<answer<< endl;
			ax = ax + dx[a_list[time]];
			ay = ay + dy[a_list[time]];
			bx = bx + dx[b_list[time]];
			by = by + dy[b_list[time]];
			//cout << "t: " << time << ", answer: " << answer << endl;
		}
		cout << "#" << t << " " << answer << endl;
	}
}