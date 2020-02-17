#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

/* 남극기지
	최적화문제를 결정문제로 바꾼 뒤, 이분법을 이용해 해결 (아래 mid를 사용하는 부분)
	최적화 문제 = 실수 or 정수, 답의 경우가 무한함
	결정문제 = yes or no, 두가지 답만 존재
*/

double pos[101][2]; // 기지의 위치
double dist[101][101]; //두 점 사이의 거리
int n; //기지의 수


bool decision(double d) { // 결정문제 -> d이하로 모든 기지를 하나로 연결할 수 있는가
	//너비우선탐색으로 d이하인 지점 사이에 간선이 있다 생각하고 전부 연결되는지 확인
	vector<bool> visited(n, false);
	visited[0] = true; // 0번째 지점부터 시작
	queue<int> q;
	q.push(0);
	int seen = 0; // 본 지점의 수, seen == n이면 모든 지점이 다 연결되어 있다는 의미
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

double optimize() { //최적화 문제 -> 최소 무전기 반경 구하는 함수
	double lo = 0, hi = 1416.00; //루트2는 1.414~~~
	for (int it = 0; it < 100; it++) {
		double mid = (lo + hi) / 2;
		//결정문제로 범위를 줄여나간다.
		if (decision(mid)) //d이하로 다 연결할 수 있으면 lo-mid사이의 중간값을 이용
			hi = mid;
		else //d이하로 다 연결할 수 없으면 mid-hi사이의 중간값을 이용
			lo = mid;
	}
	return hi;
}


int main() {
	int c;
	double x, y; //기지의 좌표 (x,y)
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%lf %lf", &pos[i][0], &pos[i][1]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2)); // (x1-x2)^2+(y1-y2)^2 루트
				dist[j][i] = dist[i][j];
			}
		}
		printf("%.2f\n", optimize());
	}
	return 0;
}

