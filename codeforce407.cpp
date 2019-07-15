#include <iostream>
#include <math.h>
using namespace std;

int input[100002] = { 0, };
int cache[100002] = { 0, };

int main() {
	int n, temp = 0, result;
	int mult = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	result = abs(input[1] - input[0]);
	for (int i = n-1; i > 0; i--) {
		cache[i] = abs(input[i - 1] - input[i]); // n부터 1까지
		temp = cache[i];
		if (result < temp) result = temp;
		for (int j = i+1; j < n-1; j+=2) {
			temp = temp - cache[j] + cache[j + 1];
			if (result < temp)
				result = temp;
		}
	}
	cout << result;
	cin >> n;
	return 0;
}
