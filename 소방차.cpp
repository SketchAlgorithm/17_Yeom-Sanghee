#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int V, E, n, m;
vector<vector<pair<int, int>>> adj;  //인접 리스트
int fire[1002];
const int INF = 987654321;

//다익스트라
vector<int> dijkstra(int x)
{
	vector<int> dist(V + 1, INF);
	dist[x] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, x));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main()
{
	int C;
	cin >> C;

	while (C--) {
		cin >> V >> E >> n >> m;
		//노드가 1부터 시작해서
		adj = vector<vector<pair<int, int>>>(V+1, vector<pair<int, int>>());
		//엣지 추가
		for (int i = 0; i < E; ++i){
			int n1, n2, n3;
			cin >> n1 >> n2 >> n3;
			adj[n1].push_back(make_pair(n2, n3));
			adj[n2].push_back(make_pair(n1, n3));
		}

		//불난 곳
		for (int i = 0; i < n; ++i)
			cin >> fire[i];

		//소방서
		for (int i = 0; i < m; ++i) {
			int num;
			cin >> num;
			adj[0].push_back(make_pair(num, 0));
			adj[num].push_back(make_pair(0, 0));
		}

		vector<int> dist;
		dist = dijkstra(0);
		//불난 곳에서 걸리는 시간 계산
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += dist[fire[i]];
		cout << sum << "\n";
	}
	return 0;
}