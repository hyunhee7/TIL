/*
	10:45 - 12:15
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[14][21];
int k;
int d, w;
int answer;
bool isAns = false;
bool test() {
	/*cout << "----------" << endl;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}*/
	
	//k�� ���� �˻�
	int total = 0; bool isFin = false;
	for (int i = 0; i < w; i++) {
		int start = map[0][i];
		int num = 1;
		isFin = false;
		for (int j = 1; j < d; j++) {
			
			if (start == map[j][i]) {
				num++;
			}
			else {
				if (j >= d - k + 1) {
					isFin = true;
					break;
				}
				start = map[j][i];
				num = 1;
				continue;
			}
			//cout << "i: " << i << ", j: " << j <<"num: " << num << endl;
			if (num == k) {
				total++;
				break;
			}
		}
		if (isFin) break;
	}
	//cout << total << endl;
	if (total == w) return true;
	return false;
	
}
void dfs(int index, int cnt, int val) {
	if (isAns) return;
	if (cnt == val) {
		//�˻��ϱ�
		isAns = test();
		if (isAns) answer = val;
		return;
	}
	if (index >= d)return;
	//�����ϱ�
	//����ĭ �ѱ��
	dfs(index + 1, cnt, val);
	//cntĭ ����
	int tmp[21];
	for (int i = 0; i < w; i++) {
		tmp[i] = map[index][i];
	}
	//������ dfs
	for (int i = 0; i < w; i++) {
		map[index][i] = 0;
	}
	dfs(index + 1, cnt + 1, val);
	for (int i = 0; i < w; i++) {
		map[index][i] = 1;
	}
	dfs(index + 1, cnt + 1, val);
	//������ ����
	for (int i = 0; i < w; i++) {
		map[index][i] = tmp[i];
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//�ʱ�ȭ
		answer = 0;
		isAns = false;
		//�Է�
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		if (k > 1) {
			//val : �ִ� ���� Ƚ��
			for (int val = 0; val <= d; val++) {
				//����
				if (val == 0) {
					if (test()) break;
				}
				else if (val > 0) dfs(0, 0, val);
				if (isAns) break;
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
}