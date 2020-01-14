#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	long long int cache2 = 0;
	vector<long long int>v;
	int n, x;
	scanf("%d %d", &n, &x);

	long long int temp;
	long long int max2 = 0;

	int start = 0, end = -1;
	int t_start = 0, t_end = -1;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &temp);
		v.push_back(temp);
		if (cache2 < 0) t_start = i, t_end = i;
		else t_end++;
		cache2 = max((long long)0, cache2) + temp * x;
		if (cache2 > max2) {
			start = t_start;
			end = t_end;
			max2 = cache2;
		}
	}
	if (end != -1) {
		for (int i = start; i <= end; i++) {
			v[i] = v[i] * x;
		}
	}

	cache2 = 0;
	for (int i = 0; i < n; i++) {
		cache2 = max((long long)0, cache2) + v[i];
		if (cache2 > max2) {
			max2 = cache2;
		}
	}

	cout << max2;
	return 0;
}