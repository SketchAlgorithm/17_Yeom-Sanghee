#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000000;
int ret[102][102];
vector<pair<int, int>> edge[101];
int n, m;
int main() {
	//√ ±‚»≠
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == j)
				ret[i][j] = 0;
			else
				ret[i][j] = INF;
		}
	}
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (ret[a][b] > c)
			ret[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(ret[i][j]>ret[i][k]+ret[k][j])
					ret[i][j] = ret[i][k] + ret[k][j];
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ret[i][j] == INF)
				cout << 0 << " ";
			else
				cout << ret[i][j] << " ";
		}
		cout << endl;
	}

	cin >> n;
}