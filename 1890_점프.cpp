#include <iostream>
#include <queue>
using namespace std;
int N;
int map[101][101] = {};
long long cache[101][101] = {};

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	cache[1][1] = 1;

	for (int i = 1; i<=N; i++) {
		for (int j = 1; j<=N; j++) {
			if (map[i][j] == 0)
				continue;
			if (i + map[i][j] <= N)
				cache[i + map[i][j]][j] += cache[i][j];

			if (j + map[i][j] <= N)
				cache[i][j + map[i][j]] += cache[i][j];
		}
	}
	cout << cache[N][N];
	return 0;
}