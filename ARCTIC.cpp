#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

/* ���ر���
	����ȭ������ ���������� �ٲ� ��, �̺й��� �̿��� �ذ� (�Ʒ� mid�� ����ϴ� �κ�)
	����ȭ ���� = �Ǽ� or ����, ���� ��찡 ������
	�������� = yes or no, �ΰ��� �丸 ����
*/

double pos[101][2]; // ������ ��ġ
double dist[101][101]; //�� �� ������ �Ÿ�
int n; //������ ��


bool decision(double d) { // �������� -> d���Ϸ� ��� ������ �ϳ��� ������ �� �ִ°�
	//�ʺ�켱Ž������ d������ ���� ���̿� ������ �ִ� �����ϰ� ���� ����Ǵ��� Ȯ��
	vector<bool> visited(n, false);
	visited[0] = true; // 0��° �������� ����
	queue<int> q;
	q.push(0);
	int seen = 0; // �� ������ ��, seen == n�̸� ��� ������ �� ����Ǿ� �ִٴ� �ǹ�
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for (int there = 0; there < n; there++) {
			if (!visited[there] && dist[here][there] <= d) {
				q.push(there);
				visited[there] = true;
			}
		}
	}
	return seen == n;
}

double optimize() { //����ȭ ���� -> �ּ� ������ �ݰ� ���ϴ� �Լ�
	double lo = 0, hi = 1416.00; //��Ʈ2�� 1.414~~~
	for (int it = 0; it < 100; it++) {
		double mid = (lo + hi) / 2;
		//���������� ������ �ٿ�������.
		if (decision(mid)) //d���Ϸ� �� ������ �� ������ lo-mid������ �߰����� �̿�
			hi = mid;
		else //d���Ϸ� �� ������ �� ������ mid-hi������ �߰����� �̿�
			lo = mid;
	}
	return hi;
}


int main() {
	int c;
	double x, y; //������ ��ǥ (x,y)
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%lf %lf", &pos[i][0], &pos[i][1]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2)); // (x1-x2)^2+(y1-y2)^2 ��Ʈ
				dist[j][i] = dist[i][j];
			}
		}
		printf("%.2f\n", optimize());
	}
	return 0;
}

