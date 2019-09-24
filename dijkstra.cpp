#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int V;
const int MAX_V = 1000;
int INF = 1000000; //��û ū ��
vector<pair<int, int>> adj[MAX_V]; //��������Ʈ(����� ���� ��ȣ, ���� ����ġ)��

vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0; //���� ���� �ʱ�ȭ
	priority_queue<pair<int, int>> pq; //������ ���� (�����ͺ��� �����Ϸ���)
	//pair���� ���� ù��° ���Ҹ� ���� ���ϹǷ� ���������� �Ÿ��� ù��° ���ҷ�
	pq.push(make_pair(0, src)); //���������� �ִܰŸ�, ����

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = -pq.top().second;
		pq.pop();
		//���ְ� �ִ� ���� �ƴ϶� �ߺ� ���Ҹ� �ִ� �������
		//-> ���� ���� �ͺ��� �� ª�� ��θ� �˰��ִٸ� ���� �� ����
		if (dist[here] < cost) continue;
		//������ �������� ��� �˻�
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			//�� ª�� ��θ� �߰��ϸ� dist[]�����ϰ� ť�� �ֱ�
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

