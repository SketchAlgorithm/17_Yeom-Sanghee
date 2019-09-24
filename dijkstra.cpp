#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int V;
const int MAX_V = 1000;
int INF = 1000000; //엄청 큰 값
vector<pair<int, int>> adj[MAX_V]; //인접리스트(연결된 정점 번호, 간선 가중치)쌍

vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0; //시작 지점 초기화
	priority_queue<pair<int, int>> pq; //음수로 저장 (적은것부터 정렬하려고)
	//pair비교할 때는 첫번째 원소를 원저 비교하므로 정점까지의 거리를 첫번째 원소로
	pq.push(make_pair(0, src)); //정점까지의 최단거리, 정점

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = -pq.top().second;
		pq.pop();
		//없애고 넣는 것이 아니라 중복 원소를 넣는 방식으로
		//-> 지금 꺼낸 것보다 더 짧은 경로를 알고있다면 꺼낸 것 무시
		if (dist[here] < cost) continue;
		//인접한 정점들을 모두 검사
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			//더 짧은 경로를 발견하면 dist[]갱신하고 큐에 넣기
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	
	for (int i = 0; i < V; i++) {
		cout << dist[i] << endl;
	}
	return dist;
}
int main() {
	int src;
	cin >> V >>src;
	for (int i = 0; i < V; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back(make_pair(u, w));
	}
}

