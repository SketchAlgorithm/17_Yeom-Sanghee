#include<iostream>
#include <algorithm>
using namespace std;

int tree[1000000] = {0,};
int ret[12] = { 0, };

bool desc(int a, int b) {
	return a > b;
};

int calc(int n, int m);

int main() {
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; j++)
			cin >> tree[j];
		sort(tree, tree + n, desc);
		
		ret[i] = calc(n, m);
	}

	for (int i = 0; i < c; i++) {
		cout << "#" << i + 1 <<" "<< ret[i] << endl;
	}

	return 0;
}

int calc(int n, int m) {
	int ret = tree[0]-1;
	int now_m = 0;
	int tree_point = 0;

	for (int i = ret; i >=0; i--) {
		while (1) {
			if (tree_point == n || tree[tree_point] <= i) {
				now_m += (tree_point) * 1;
				break;
			}
			else tree_point++;
		}
		if (now_m >= m)
			return i;
	}
}