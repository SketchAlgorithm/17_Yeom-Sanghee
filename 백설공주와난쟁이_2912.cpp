/*
확률을 사용
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, c, m;
	vector <int> arr;

	vector<vector<int>> color; //color[num] => 해당 색의 모자를 쓴 난쟁이 번호 (오름차순)
	scanf("%d %d", &n, &c);

	color.resize(c + 1); // 색의 수만큼 사이즈 재정의

	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		arr.push_back(temp);
		color[temp].push_back(i + 1); //난쟁이 수는 1부터니깐
	}
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, num;
		bool check = false;
		scanf("%d %d", &a, &b);
		//확률을 활용
		for (int j = 0; j < 16; j++) {
			num = rand() % (b-a+1) + a-1;
			num = arr[num];

			int cnt = upper_bound(color[num].begin(), color[num].end(), b) - lower_bound(color[num].begin(), color[num].end(), a); //이진탐색 활용
			if (cnt > (b - a + 1) / 2) {
				printf("yes %d\n", num);
				check = true;
				break;
			}
		}
		if (!check) printf("no\n");
	}
	cin >> n;
	return 0;
}