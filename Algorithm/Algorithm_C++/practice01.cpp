#include <iostream>
using namespace std;
int map[21];
int sum(int val) {
	if (val == 1)return 1;
	return val + sum(val - 1);
}
int binarySearch(int arr[], int len, int x) {
	int l = 0;
	int r = len;
	int mid;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) {
			r = mid - 1;
		}
		else if (arr[mid] > x) {
			l = mid - 1;
		}
	}
}
int linearSearch(int arr[], int len, int x) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == x) return i;
	}
	return -1;
}
int main() {
	for (int i = 1; i <= 20; i++) {
		map[i] = i;
	}
	cout << "1부터 15의 합: " << sum(15) << endl;
}