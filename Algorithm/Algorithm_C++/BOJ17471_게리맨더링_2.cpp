#include<iostream>
using namespace std;
int n;
int a[11];
int map[11][11];
int c[11];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1,t; i <= n; i++) {
		cin >> t;
		for (int j = 0, tmp; j < t; j++) {
			cin >> tmp;
			map[i][tmp] = 1;
		}
	}
	/*
		bitmask½áº¸±â
	*/
}