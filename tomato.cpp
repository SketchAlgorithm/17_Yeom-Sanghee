#include <iostream>
#include <queue>

int arr[1001][1001];
int cache[1001][1001] = { -1, };
using namespace std;

int main() {
	int max = 0;
	queue<pair<int, int>> q;
	int row, col; // (row, col) = (y,x)
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(pair<int, int>(i, j)); //(y,x)
				cache[i][j] = 0;
			}
			else cache[i][j] = -1;
		}
	}
	while (!q.empty()) {
		int q_y = q.front().first; //row
		int q_x = q.front().second; //col
		q.pop();

		for (int i = 0; i < 4;i++) { // -1, 1
			int x = q_x, y = q_y;
			if (i == 0)x = x - 1;
			else if (i == 1) x = x + 1;
			else if (i == 2) y = y - 1;
			else y = y + 1;

			if (y < 0 || y >= row || x < 0 || x >= col)
				continue;
			switch (arr[y][x]) {
			case -1:
				break;
			case 0:
				arr[y][x] = 2;
				q.push(pair<int, int>(y, x));
				if (cache[y][x] == -1)
					cache[y][x] = cache[q_y][q_x] + 1;
				else
					if (cache[y][x] > cache[q_y][q_x] + 1) cache[y][x] = cache[q_y][q_x] + 1;
				break;
			case 1:
				cache[y][x] = 0;
				break;
			case 2:
				break;

			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j]!=-1 && cache[i][j] == -1) {
				max = -1;
			}
			else if (max!=-1 && max < cache[i][j]) max = cache[i][j];
		}
	}
	cout << max;
	cin >> row;
	return 0;
}