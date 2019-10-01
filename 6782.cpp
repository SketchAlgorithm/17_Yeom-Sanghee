#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

long long int calc(long long int N, long long int count) {
	long long int rootN = sqrt(N);
	long long int nextN = (rootN + 1)*(rootN + 1);

	if (N == 2)
		return count;
	else if (rootN*rootN == N)
		return calc(rootN, ++count);
	else
		return calc(nextN, count + nextN-N);
};

int main() {
	int C;
	long long N;
	vector<long long> ret;

	cin >> C;	

	for (int i = 0; i < C; i++) {
		cin >> N;
		ret.push_back(calc(N, 0));
	}
	
	for (int i = 0; i < ret.size(); i++)
		cout << "#" << i + 1 <<" "<< ret.at(i)<<endl;

	ret.clear();
}