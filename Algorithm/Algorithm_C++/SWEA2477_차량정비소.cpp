#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, N, M, K, A, B, answer;
struct customer {
	int tk;
	int k;
	int ak = 0;
	int bk = 0;
	customer(int tk, int k) : tk{ tk }, k{ k } {};
};
void findCustomer(vector<customer> &cus, vector<int> a, vector<int> b) {
	int time = 0, endCount = 0;
	queue<int> reception, repair; //고객번호
	vector<pair<int, int>> receptionINFO; //고객번호, 접수 소요 시간
	vector<pair<int, int>> repairINFO; //고객번호, 정비 소요 시간
	receptionINFO.resize(a.size());
	repairINFO.resize(b.size());
	
	while (1) {
		for (int i = 0; i < K; i++) {
			if (cus[i].tk == time) {
				reception.push(i);
			}
		}

		for (int i = 0; i < N; i++) {
			if (reception.empty()) break;
			if (receptionINFO[i].second == 0) {
				receptionINFO[i].first = reception.front();
				receptionINFO[i].second = a[i];
				cus[receptionINFO[i].first].ak = i + 1;
				reception.pop();
			}
		}

		for (int i = 0; i < receptionINFO.size(); i++) {
			if (receptionINFO[i].second == 0) {
				continue;
			}
			receptionINFO[i].second--;
			if (receptionINFO[i].second == 0) {
				repair.push(receptionINFO[i].first);
			}
		}
		for (int i = 0; i < M; i++) {
			if (repair.empty()) break;
			if (repairINFO[i].second == 0) {
				repairINFO[i].first = repair.front();
				repairINFO[i].second = b[i];
				cus[repairINFO[i].first].bk = i + 1;
				repair.pop();
			}
		}
		for (int i = 0; i < repairINFO.size(); i++) {
			if (repairINFO[i].second == 0) {
				continue;
			}
			repairINFO[i].second--;
			if (repairINFO[i].second == 0) {
				endCount++;
			}
		}
		if (endCount == K) {
			for (int i = 0; i < K; i++) {
				if (cus[i].ak == A && cus[i].bk == B) {
					answer += (i + 1);
				}
			}
			break;
		}
		time++;
	}
}
int main() {
	cin >> T;
	int temp;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> K >> A >> B;
		vector<int> a;
		vector<int> b;
		vector<customer> cus;
		answer = 0;

		for (int j = 0; j < N; j++) {
			cin >> temp;
			a.push_back(temp);
		}
		for (int j = 0; j < M; j++) {
			cin >> temp;
			b.push_back(temp);
		}
		for (int j = 0; j < K; j++) {
			cin >> temp;
			cus.push_back(customer(temp, j));
		}
		findCustomer(cus, a, b);
		if (answer == 0) {
			answer = -1;
		}
		cout << "#" << i << " " << answer << endl;
	}
}
