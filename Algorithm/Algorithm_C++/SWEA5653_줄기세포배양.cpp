///*
//	
//*/
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, k;
//int answer;
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//struct cell {
//	int x, y;
//	int life;
//	int t;
//	int status;
//};
//cell map[660][660];
//vector<cell> cells;
//int main() {
//	//int t;
//	//cin >> t;
//	//for (int t = 1; t <= t; t++) {
//		//입력
//		answer = 0;
//		cin >> n >> m >> k;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				int life;
//				cin >> life;
//				if (life == 0) continue;
//				cell cell;
//				cell.x = i+300;
//				cell.y = j+300;
//				cell.life = life;
//				cell.t = life;
//				cell.status = 0;
//				map[cell.x][cell.y] = cell;
//				cells.push_back(cell);
//			}
//		}
//		vector<cell> tmp_cells;
//		for (int time = 0; time < k; time++) {
//			//활성 상태 번식
//			for (int i = 0; i < cells.size(); i++) {
//				if (cells[i].status == 1 && cells[i].t == cells[i].life) {
//					int x = cells[i].x;
//					int y = cells[i].y;
//					for (int i = 0; i < 4; i++) {
//						int nx = x + dx[i];
//						int ny = y + dy[i];
//						if (sizeof(map[nx][ny]) != 0) continue;
//						cell cell;
//						cell.x = nx;
//						cell.y = ny;
//						cell.life = cells[i].life;
//						cell.t = cells[i].life;
//						cell.status = 0;
//						tmp_cells.push_back(cell);
//					}
//				}
//			}
//			//life감소
//			for (int i = 0; i < cells.size(); i++) {
//				if (cells[i].status == -1) continue;
//				cells[i].t--;
//			}
//			//세포 상태 바꾸기
//			for (int i = 0; i < cells.size(); i++) {
//				if (cells[i].status == -1) continue;
//				if (cells[i].status == 0 && cells[i].t == 0) cells[i].status = 1;
//				if (cells[i].status == 1 && cells[i].t == 0) cells[i].status = -1;
//			}
//			for (int i = 0; i < tmp_cells.size(); i++) {
//				cout << sizeof(map[tmp_cells[i].x][tmp_cells[i].y]) << endl;
//				if (sizeof(map[tmp_cells[i].x][tmp_cells[i].y]) == 0) {
//					map[tmp_cells[i].x][tmp_cells[i].y] = tmp_cells[i];
//					cells.push_back(tmp_cells[i]);
//				}
//				else {
//					if (map[tmp_cells[i].x][tmp_cells[i].y].life < tmp_cells[i].life) {
//						map[tmp_cells[i].x][tmp_cells[i].y] = tmp_cells[i];
//						cells.push_back(tmp_cells[i]);
//					}
//				}
//			}
//		}
//		//살아있는 세포 count
//		for (int i = 0; i < cells.size(); i++) {
//			if (cells[i].status == 0 && cells[i].status == 1) {
//				answer++;
//			}
//		}
//		cout << answer;
//	//}
//}