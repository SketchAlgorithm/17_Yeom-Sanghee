#include <iostream>
#include <vector>
using namespace std;
bool visited[15] = { 0, };
double edge[15][15] = { -1, };
double m_dist;
double ret[50];
int C, N; // N은 도시 개수

void tsp(int node, double dist, int count) {
	visited[node] = true;

	if (count == N) {
		visited[node] = false;
		if (m_dist > dist)
			m_dist = dist;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && edge[node][i] != 0)
			tsp(i, dist + edge[node][i], count + 1);
	}
	visited[node] = false;
}
int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		m_dist = 1000000;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> edge[j][k]; // j -> k
			}
		}
		for (int j = 0; j < N; j++) {
			tsp(j, 0, 1);
		}
		ret[i] = m_dist;
	}

	for (int i = 0; i < C; i++) {
		printf("%.10f\n", ret[i]);
	}
}