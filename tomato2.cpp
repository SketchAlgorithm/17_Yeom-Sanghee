//#include <iostream>
//#include <queue>
//
//
//int arr[101][101][101]; //�Է� (����, row, col)
//int cache[101][101][101] = { -1, }; //�ʹµ� �ɸ��� �ּ� ��
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
//�迭 ũ�⸦ n*m�̶� �ϸ�
//�Է� : O(n*m)
//�ʹµ� �ɸ��� �ּ� �� ���ϱ� : O(n*m*4) -> �� ��ġ���� 4�� ���ϱ�
//�ִ� �� Ȯ�� : O(n*m)
//*/
//
//int main() {
//	int max = 0;
//	queue<Place> q;
//	int row, col, height; // (row, col) = (y,x), ����
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
//		for (int i = 0; i <6; i++) { // 4��� Ȯ��
//			int x = q_x, y = q_y, h = q_h;
//			if (i == 0)x = x - 1;
//			else if (i == 1) x = x + 1;
//			else if (i == 2) y = y - 1;
//			else if (i == 3) y = y + 1;
//			else if (i == 4) h = h - 1;
//			else h = h + 1;
//
//			if (y < 0 || y >= row || x < 0 || x >= col || h < 0 || h >= height) //���� ������ ����
//				continue;
//
//			switch (arr[h][y][x]) {
//			case -1: // ������ ���̸� pass
//				break;
//			case 0: //0�̸� queue�� �߰��ϰ� �̹� ���ٴ� ǥ�÷� 2�� �ٲ�
//					//�� �� cache�� �� ���� ������� ����
//				arr[h][y][x] = 2;
//				q.push(Place(h, y, x));
//				if (cache[h][y][x] == -1)
//					cache[h][y][x] = cache[q_h][q_y][q_x] + 1;
//				else
//					if (cache[h][y][x] > cache[q_h][q_y][q_x] + 1) cache[h][y][x] = cache[q_h][q_y][q_x] + 1;
//				break;
//			case 1: //1�̸� 0���� (���� �;��־����ϱ�)
//				cache[h][y][x] = 0;
//				break;
//			case 2: //�̹� �;����� pass
//				break;
//
//			}
//		}
//	}
//	for (int k = 0; k < height; k++) {
//		for (int i = 0; i < row; i++) {
//			for (int j = 0; j < col; j++) { //�丶�䰡 �ִµ� �� �;����� -1, �ƴϸ� �ִ� �ɸ� ���� max ����
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