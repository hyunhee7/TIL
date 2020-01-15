#include <iostream>
using namespace std;
int map[51][51];
bool visited[51][51];
int n, m;
int r, c, d;
int answer = 0;
bool changedir() {
	//û�ұ� �̵� ����
	bool isMove = false;

	//û�� ���� ����
	if (d == 0) {
		//û�� ������ ���
		if (map[r][c-1] == 0 && !visited[r][c-1]) {
			//û�ұ� ���� ���� Ʋ��
			d--;
			//��ĭ ����
			c -= 1;
			isMove = true;
		}
		//���� ���
		else {
			d--;
			isMove = false;
		}
	}
	else if (d == 1) {
		//û�� ������ ���
		if (map[r-1][c] == 0 && !visited[r-1][c]) {
			d--;
			r -= 1;
			isMove = true;
		}
		//���� ���
		else {
			d--;
			isMove = false;
		}
	}
	else if (d == 2) {
		//û�� ������ ���
		if (map[r][c + 1] == 0 && !visited[r][c + 1]) {
			d--;
			c += 1;
			isMove = true;
		}
		//���� ���
		else {
			d--;
			isMove = false;
		}
	}
	else {
		//û�� ������ ���
		if (map[r+1][c] == 0 && !visited[r+1][c]) {
			d--;
			r += 1;
			isMove = true;
		}
		//���� ���
		else {
			d--;
			isMove = false;
		}
	}
	if (d < 0) d = 3;

	return isMove;
}
int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//�ϵ�����0123
	bool isStop = false;
	
	while (!isStop) {
		//1.û��
		if (!visited[r][c]) {
			visited[r][c] = true;
			answer++;
		}
		
		bool isMove = false;

		//2.����ٲٱ�
		for (int i = 0; i < 4; i++) {

			isMove = changedir();
			if (isMove) {
				break;
			}
		}
		//3.����Ȯ��
		if (!isMove) {
			//����
			if (d == 0) {
				if (map[r+1][c]==0 && visited[r+1][c] == 1)
					r++;
				else
					isStop = true;
			}
			else if (d == 1) {
				if (map[r][c-1] == 0 && visited[r][c - 1] == 1)
					c--;
				else
					isStop = true;
			}
			else if (d == 2) {
				if (map[r - 1][c] == 0 && visited[r - 1][c] == 1)
					r--;
				else
					isStop = true;
			}
			else{
				if (map[r][c+1] == 0 && visited[r][c + 1] == 1)
					c++;
				else
					isStop = true;
			}
		}
	}
	cout << answer;
}