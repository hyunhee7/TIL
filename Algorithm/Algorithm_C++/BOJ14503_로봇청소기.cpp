#include <iostream>
using namespace std;
int map[51][51];
bool visited[51][51];
int n, m;
int r, c, d;
int answer = 0;
bool changedir() {
	//청소기 이동 여부
	bool isMove = false;

	//청소 가능 여부
	if (d == 0) {
		//청소 가능할 경우
		if (map[r][c-1] == 0 && !visited[r][c-1]) {
			//청소기 방향 왼쪽 틀기
			d--;
			//한칸 전진
			c -= 1;
			isMove = true;
		}
		//못할 경우
		else {
			d--;
			isMove = false;
		}
	}
	else if (d == 1) {
		//청소 가능할 경우
		if (map[r-1][c] == 0 && !visited[r-1][c]) {
			d--;
			r -= 1;
			isMove = true;
		}
		//못할 경우
		else {
			d--;
			isMove = false;
		}
	}
	else if (d == 2) {
		//청소 가능할 경우
		if (map[r][c + 1] == 0 && !visited[r][c + 1]) {
			d--;
			c += 1;
			isMove = true;
		}
		//못할 경우
		else {
			d--;
			isMove = false;
		}
	}
	else {
		//청소 가능할 경우
		if (map[r+1][c] == 0 && !visited[r+1][c]) {
			d--;
			r += 1;
			isMove = true;
		}
		//못할 경우
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
	//북동남서0123
	bool isStop = false;
	
	while (!isStop) {
		//1.청소
		if (!visited[r][c]) {
			visited[r][c] = true;
			answer++;
		}
		
		bool isMove = false;

		//2.방향바꾸기
		for (int i = 0; i < 4; i++) {

			isMove = changedir();
			if (isMove) {
				break;
			}
		}
		//3.종료확인
		if (!isMove) {
			//후진
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