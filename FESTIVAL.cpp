#include <iostream>

using namespace std;

int value[1002] = { 0, }; //대여비용 저장
double ret[102] = { 0, }; //최소 평균 저장

double calc(int n, int l); // 최소 평균 비용 구하는 함수

int main() {
	int c; //케이스 수
	int n; //대여할 수 있는 날
	int l; //섭외한 팀 수
	//입력
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> l;
		for (int j = 0; j < n; j++)
			cin >> value[j];
		ret[i] = calc(n, l);
	}

	for (int i = 0; i < c; i++) {
		printf("%.12f\n", ret[i]);
	}

	return 0;
}

double calc(int n, int l) { // 최소 평균 비용 구하는 함수
	double ret = 0;
	int temp = 0;

	for (int j = n-l; j <n ; j++) { //제일 마지막 경우만 먼저 계산
		temp += value[j];
	}

	ret = (double)temp / l;

	for (int i = 0; i < n - l; i++) {
		temp = 0;

		for (int j = 0; j < l; j++) { //처음 필요한 팀만큼 계산
			temp += value[i + j];
		}

		if ((double)temp / l < ret)
			ret = (double)temp / l;


		for (int j = i + l; j < n; j++) { //하나씩 추가하며 계산
			temp += value[j];
			if ((double)temp/ (j-i+1) < ret)
				ret = (double)temp/ (j - i + 1);
		}
	}
	return ret;
}