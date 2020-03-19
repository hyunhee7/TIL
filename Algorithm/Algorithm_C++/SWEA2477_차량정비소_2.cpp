#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, a, b;
int k;
int answer;
struct customer {
	int tk;
	int k;
	int ak;
	int bk;
};
void findCustomer(vector<customer> &cus, vector<int> alist, vector<int> blist) {
	queue<int> reception;
	queue<int> repair;
	vector<pair<int, int>> receptionInfo;
	vector<pair<int, int>> repairInfo;
	receptionInfo.resize(alist.size());
	repairInfo.resize(blist.size());
	int time = 0;
	int endCount = 0;
	while (true) {
		//1. 시간되면
		for (int i = 0; i < k; i++) {
			if (cus[i].tk == time) {
				reception.push(i);
			}
		}
		//2. reception --> receptionInfo
		for (int i = 0; i < n; i++) {
			if (reception.empty()) break;
			if (receptionInfo[i].second == 0) {
				int index = reception.front();
				receptionInfo[i].first = index;
				receptionInfo[i].second = alist[i];
				cus[receptionInfo[i].first].ak = i + 1;
				reception.pop();
			}
		}
		//3. receptionInfo 시간관리
		for (int i = 0; i < receptionInfo.size(); i++) {
			if (receptionInfo[i].second == 0) continue;
			receptionInfo[i].second--;
			if (receptionInfo[i].second == 0) {
				repair.push(receptionInfo[i].first);
			}
		}
		//4. repair --> repairInfo
		for (int i = 0; i < m; i++) {
			if (repair.empty()) break;
			if (repairInfo[i].second == 0) {
				int index = repair.front();
				repair.pop();
				repairInfo[i].first = index;
				repairInfo[i].second = blist[i];
				cus[repairInfo[i].first].bk = i + 1;
			}
		}
		//5. repairInfo 시간관리
		for (int i = 0; i < repairInfo.size(); i++) {
			if (repairInfo[i].second == 0)continue;
			repairInfo[i].second--;
			if (repairInfo[i].second == 0) {
				endCount++;
			}
		}
		//6. endCount==k 종료
		if (endCount == k) {
			for (int i = 0; i < k; i++) {
				if (a == cus[i].ak && b == cus[i].bk) answer += (i + 1);
			}
			break;
		}
		time++;
	}

}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		answer = 0;
		cin >> n >> m >> k >> a >> b;
		vector<int> alist;
		vector<int> blist;
		vector<customer> cus;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			alist.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			blist.push_back(tmp);
		}
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			customer c;
			c.k = i;
			c.tk = tmp;
			c.ak = 0;
			c.bk = 0;
			cus.push_back(c);
		}
		findCustomer(cus, alist, blist);
		if (answer == 0) {
			answer = -1;
		}
		cout << "#" << t << " " << answer << endl;
	}
}