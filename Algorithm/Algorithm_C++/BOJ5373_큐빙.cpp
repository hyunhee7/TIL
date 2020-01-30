/*
	11:10-12:40
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
char order[1001][2];
char u[3][3];
char d[3][3];
char f[3][3];
char b[3][3];
char l[3][3];
char r[3][3];
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//초기화
		n = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				u[i][j] = 'w';
				d[i][j] = 'y';
				f[i][j] = 'r';
				b[i][j] = 'o';
				l[i][j] = 'g';
				r[i][j] = 'b';
			}
		}
		//입력
		cin >> n;
		for (int i = 0; i < n; i++) {
			//돌린 면(u,d,f,b,l,r), 돌린 방향(시계,반시계)
			string line;
			cin >> line;
			order[i][0] = line[0];
			order[i][1] = line[1];
		}
		//회전
		for (int i = 0; i < n; i++) {
			//위
			if (order[i][0] == 'U') {
				vector<char> ff;
				vector<char> ll;
				vector<char> bb;
				vector<char> rr;

				for (int i = 0; i < 3; i++) {
					ff.push_back(f[0][i]);
					ll.push_back(l[0][i]);
					bb.push_back(b[0][i]);
					rr.push_back(r[0][i]);
				}

				if (order[i][1] == '+') {
					for (int i = 0; i < 3; i++) {
						f[0][i] = rr[i];
						r[0][i] = bb[i];
						b[0][i] = ll[i];
						l[0][i] = ff[i];
					}
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = u[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							u[p][2 - i] = v[p];
						}
					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						f[0][i] = ll[i];
						l[0][i] = bb[i];
						b[0][i] = rr[i];
						r[0][i] = ff[i];
					}
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = u[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							u[2-p][i] = v[p];
						}
					}
				}

			}else if (order[i][0] == 'D') {
				vector<char> ff;
				vector<char> ll;
				vector<char> bb;
				vector<char> rr;

				for (int i = 0; i < 3; i++) {
					ff.push_back(f[2][i]);
					ll.push_back(l[2][i]);
					bb.push_back(b[2][i]);
					rr.push_back(r[2][i]);
				}
				if (order[i][1] == '+') {
					for (int i = 0; i < 3; i++) {
						f[2][i] = ll[i];
						l[2][i] = bb[i];
						b[2][i] = rr[i];
						r[2][i] = ff[i];
					}
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = d[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							d[p][2 - i] = v[p];
						}
					}

				}
				else {
					for (int i = 0; i < 3; i++) {
						f[2][i] = rr[i];
						r[2][i] = bb[i];
						b[2][i] = ll[i];
						l[2][i] = ff[i];
					}
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = d[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							d[2 - p][i] = v[p];
						}
					}
				}
			}
			else if (order[i][0] == 'F') {
				vector<char> uu;
				vector<char> ll;
				vector<char> dd;
				vector<char> rr;

				for (int i = 0; i < 3; i++) {
					uu.push_back(u[2][i]);
					ll.push_back(l[2-i][2]);
					dd.push_back(d[0][i]);
					rr.push_back(r[2-i][0]);
				}
				if (order[i][1] == '+') {
					for (int i = 0; i < 3; i++) {
						u[2][i] = ll[i];
						l[2][i] = dd[i];
						d[2][i] = rr[i];
						r[2][i] = uu[i];
					}

					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = f[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							f[p][2 - i] = v[p];
						}
					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						u[2][2-i] = rr[i];
						r[2][2-i] = dd[i];
						d[2][2-i] = ll[i];
						l[2][2-i] = uu[i];
					}
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = f[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							f[2 - p][i] = v[p];
						}
					}
				}
			}
			else if (order[i][0] == 'B') {
				vector<char> uu;
				vector<char> ll;
				vector<char> dd;
				vector<char> rr;

				for (int i = 0; i < 3; i++) {
					uu.push_back(u[0][2-i]);
					ll.push_back(l[i][0]);
					dd.push_back(d[2][i]);
					rr.push_back(r[2-i][2]);
				}
				if (order[i][1] == '+') {
					for (int i = 0; i < 3; i++) {
						u[0][i] = rr[i];
						r[i][2] = dd[i];
						d[2][i] = ll[i];
						l[i][0] = uu[i];
					}
					
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = b[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							b[p][2 - i] = v[p];
						}
					}
				}
				else { //반시계
					for (int i = 0; i < 3; i++) {
						u[0][2-i] = ll[i];
						l[2-i][0] = dd[i];
						d[2][2-i] = rr[i];
						r[2-i][2] = uu[i];
					}
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = b[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							b[2 - p][i] = v[p];
						}
					}
				}
			}
			else if (order[i][0] == 'L') {
				int tmp1 = u[0][0];
				int tmp2 = u[1][0];
				int tmp3 = u[2][0];
				if (order[i][1] == '+') {
					for (int i = 0; i < 3; i++) {
						u[i][0] = b[2-i][2];
						b[i][0] = d[2-i][2];
						d[i][0] = f[i][0];
					}
					f[0][0] = tmp1;
					f[1][0] = tmp2;
					f[2][0] = tmp3;
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = l[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							l[p][2 - i] = v[p];
						}
					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						u[i][0] = f[i][0];
						f[i][0] = d[i][2];
						d[i][0] = b[2-i][2];
					}
					b[2][2] = tmp1;
					b[1][2] = tmp2;
					b[0][2] = tmp3;
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = l[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							l[2 - p][i] = v[p];
						}
					}
				}
			}
			else  {
				int tmp1 = u[0][2];
				int tmp2 = u[1][2];
				int tmp3 = u[2][2];
				if (order[i][1] == '+') {
					for (int i = 0; i < 3; i++) {
						u[i][2] = f[i][2];
						f[i][2] = d[i][2];
						d[i][2] = b[2-i][0];
					}
					b[0][0] = tmp3;
					b[1][0] = tmp2;
					b[2][0] = tmp1;
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = r[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							r[p][2 - i] = v[p];
						}
					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						u[i][2] = b[2-i][0];
						b[i][0] = d[2-i][2];
						d[i][2] = f[i][2];
					}
					f[0][2] = tmp1;
					f[1][2] = tmp2;
					f[2][2] = tmp3;
					int map[3][3];
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							map[i][j] = r[i][j];
						}
					}
					for (int i = 0; i < 3; i++) {
						vector<int> v;
						for (int j = 0; j < 3; j++) {
							v.push_back(map[i][j]);
						}
						for (int p = 0; p < 3; p++) {
							r[2 - p][i] = v[p];
						}
					}
				}
			}
			/*for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cout << u[i][j];
				}
				cout << endl;
			}
			cout << "-------------"<<endl;*/
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << u[i][j];
			}
			cout << endl;
		}
	}
}