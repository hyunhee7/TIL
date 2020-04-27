/*
	13:45 - 15:14
*/
#include <iostream>
using namespace std;
int map[4][2];
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> map[i][j];
		}
	}
	int answer = 0;
	int num = 0;
	for (int i = 0; i < 4; i++) {
		num -= map[i][0];
		num += map[i][1];
		if (num > answer)answer = num;
	}
	cout << answer;
}