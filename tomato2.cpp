//#include <iostream>
//#include <queue>
//
//
//int arr[101][101][101]; //입력 (높이, row, col)
//int cache[101][101][101] = { -1, }; //익는데 걸리는 최소 날
//using namespace std;
//
//struct Place {
//	int h;
//	int y;
//	int x;
//
//	Place(int _h, int _y, int _x) {
//		h = _h;
//		y = _y;
//		x = _x;
//	}
//};
//
///*
//배열 크기를 n*m이라 하면
//입력 : O(n*m)
//익는데 걸리는 최소 날 구하기 : O(n*m*4) -> 각 위치에서 4번 보니깐
//최대 값 확인 : O(n*m)
//*/
//
//int main() {
//	int max = 0;
//	queue<Place> q;
//	int row, col, height; // (row, col) = (y,x), 높이
//	cin >> col >> row >> height;
//	for (int k = 0; k < height; k++) {
//		for (int i = 0; i < row; i++) {
//			for (int j = 0; j < col; j++) {
//				cin >> arr[k][i][j];
//				if (arr[k][i][j] == 1) {
//					q.push(Place(k, i, j)); //(height, y,x)
//					cache[k][i][j] = 0;
//				}
//				else cache[k][i][j] = -1;
//			}
//		}
//	}
//
//	while (!q.empty()) {
//		int q_h = q.front().h; // height
//		int q_y = q.front().y; //row
//		int q_x = q.front().x; //col
//		q.pop();
//
//		for (int i = 0; i <6; i++) { // 4방면 확인
//			int x = q_x, y = q_y, h = q_h;
//			if (i == 0)x = x - 1;
//			else if (i == 1) x = x + 1;
//			else if (i == 2) y = y - 1;
//			else if (i == 3) y = y + 1;
//			else if (i == 4) h = h - 1;
//			else h = h + 1;
//
//			if (y < 0 || y >= row || x < 0 || x >= col || h < 0 || h >= height) //범위 넘으면 무시
//				continue;
//
//			switch (arr[h][y][x]) {
//			case -1: // 못가는 곳이면 pass
//				break;
//			case 0: //0이면 queue에 추가하고 이미 갔다는 표시로 2로 바꿈
//					//그 후 cache에 더 작은 비용으로 갱신
//				arr[h][y][x] = 2;
//				q.push(Place(h, y, x));
//				if (cache[h][y][x] == -1)
//					cache[h][y][x] = cache[q_h][q_y][q_x] + 1;
//				else
//					if (cache[h][y][x] > cache[q_h][q_y][q_x] + 1) cache[h][y][x] = cache[q_h][q_y][q_x] + 1;
//				break;
//			case 1: //1이면 0으로 (원래 익어있었으니깐)
//				cache[h][y][x] = 0;
//				break;
//			case 2: //이미 익었으면 pass
//				break;
//
//			}
//		}
//	}
//	for (int k = 0; k < height; k++) {
//		for (int i = 0; i < row; i++) {
//			for (int j = 0; j < col; j++) { //토마토가 있는데 못 익었으면 -1, 아니면 최대 걸린 날로 max 설정
//				if (arr[k][i][j] != -1 && cache[k][i][j] == -1) {
//					max = -1;
//				}
//				else if (max != -1 && max < cache[k][i][j]) max = cache[k][i][j];
//			}
//		}
//	}
//	cout << max;
//
//	return 0;
//}