/*
	13:20 - 14:50
*/
#include <iostream>
#include <math.h>
using namespace std;
int k;
int map[4][8];
int order[101][2];
bool isMove[3];

void moveLeft(int index) {//반시계
	int first = map[index][0];
	for (int j = 0; j < 7; j++) {
		map[index][j] = map[index][j + 1];
	}
	map[index][7] = first;
}
void moveRight(int index) {//시계
	int last = map[index][7];
	for (int j = 6; j >= 0; j--) {
		map[index][j + 1] = map[index][j];
	}
	map[index][0] = last;
}
void moveNow(int index, int dir) {
	if (dir == 1) {
		moveRight(index);
	}
	else
		moveLeft(index);
}
void leftSide(int index, int dir) {
	moveNow(index, dir);
	if (index - 1 < 0) return;
	if (isMove[index - 1]) {
		if (dir == 1) {
			dir = -1;
		}
		else {
			dir = 1;
		}
		//움직O
		leftSide(index - 1, dir);
	}

}
void rightSide(int index, int dir) {
	moveNow(index, dir);
	if (index + 1 > 3)return;
	if (isMove[index]) {
		if (dir == 1) {
			dir = -1;
		}
		else {
			dir = 1;
		}
		rightSide(index + 1, dir);
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < 8; j++) {
			map[i][j] = line[j]-'0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int tmp = 0;
		cin >> tmp >> order[i][1];
		order[i][0] = tmp - 1;
	}
	for (int i = 0; i < k; i++) {
		fill(isMove, isMove + 3, false);
		for (int i = 0; i < 3; i++) {
			if (map[i][2] != map[i+1][6]) {
				isMove[i] = true;
			}
		}
		moveNow(order[i][0], order[i][1]);
		int dir = 1;
		if (order[i][1] == 1) {
			dir = -1;
		}
		if (isMove[order[i][0]-1]) {
			leftSide(order[i][0] - 1, dir);
		}
		if (isMove[order[i][0]]) {
			rightSide(order[i][0] + 1, dir);
		}
		/*for (int p = 0; p < 4; p++) {
			for (int j = 0; j < 8; j++) {
				cout << map[p][j] << ' ';
			}
			cout << endl;
		}
		cout << "------" << endl;*/
	}

	int answer = 0;
	for (int i = 0; i < 4; i++) {
		//cout << map[i][0] << ' ';
		answer += pow(2,i)*map[i][0];
	}
	//cout << endl;
	cout << answer;

}