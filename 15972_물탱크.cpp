#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int,pair<int, int>>> pq;
int horiz[1002][1001] = {};
int verti[1001][1002] = {};
int arr[1001][1001] = {};
int N, M, H;
int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < M; j++) {
			cin >> horiz[i][j];
			arr[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M+1; j++) {
			cin >> verti[i][j];
		}
	}
	//외부로 나가는 것 확인
	for (int i = 0; i < M; i++) { //가로 벽
		if (horiz[0][i] != -1) {
			pq.push(make_pair(-horiz[0][i], make_pair(0, i)));
		}
		if (horiz[N][i] != -1) {
			pq.push(make_pair( -horiz[N][i], make_pair(N - 1, i)));
		}
	}

	
	for (int i = 0; i < N; i++) { //세로 벽
		if (verti[i][0] != -1) {
			pq.push(make_pair(-verti[i][0], make_pair(i, 0)));
		}
		if (verti[i][M] != -1) {
			pq.push(make_pair(-verti[i][M], make_pair(i, M - 1)));
		}
	}

	while (!pq.empty()) {
		int height = -pq.top().first;
		//(x,y) -> [x][y]
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		if (arr[x][y] != -1) {
			pq.pop();
			continue;
		}
		arr[x][y] = height;

		pq.pop();
		//조건문
		//주변에 연결된 곳 큐 넣고
		//값 지정
		//가로
		if (horiz[x][y] != -1 && x-1 >= 0) {
				if (arr[x][y] <= horiz[x][y])
					pq.push(make_pair(-horiz[x][y], make_pair(x - 1, y)));
				else
					pq.push(make_pair(-arr[x][y], make_pair(x - 1, y)));
		}
		if (horiz[x+1][y] != -1 && x +1 < N) {
				if (arr[x][y] <= horiz[x + 1][y])
					pq.push(make_pair(-horiz[x+1][y], make_pair(x + 1, y)));
				else
					pq.push(make_pair(-arr[x][y], make_pair(x + 1, y)));
		}
		if (verti[x][y] != -1 && y - 1 >= 0) {
				if (arr[x][y] <= verti[x][y])
					pq.push(make_pair(-verti[x][y], make_pair(x, y - 1)));
				else
					pq.push(make_pair(-arr[x][y], make_pair(x, y - 1)));
		}
		if (verti[x][y+1] != -1 && y + 1 < M) {
				if (arr[x][y] <= verti[x][y + 1])
					pq.push(make_pair(-verti[x][y+1], make_pair(x, y + 1)));
				else
				pq.push(make_pair(-arr[x][y], make_pair(x, y + 1)));
			}
	}
	
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != -1) ret += arr[i][j];
			else
				ret += H;
		}
	}

	cout << ret;
	cin >> ret;
	return 0;
}
