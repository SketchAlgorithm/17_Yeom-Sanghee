#include <iostream>
#include <map>
using namespace std;
map<int, int> pos;
bool isDominated(int x, int y) {
	map<int, int>::iterator it = pos.lower_bound(x);
	if (it == pos.end()) return false;
	return y < it->second;
}

void removeDominated(int x, int y) {
	map<int, int>::iterator it = pos.lower_bound(x);
	if (it == pos.begin())return;
	it--;
	while (true) {
		if (it->second > y) break;
		if (it == pos.begin()) {
			pos.erase(it);
			break;
		}
		else {
			map<int, int>::iterator dt = it;
			dt--;
			pos.erase(it);
			it = dt;
		}
	}
}

int count(int x, int y) {
	if (isDominated(x, y)) return pos.size();
	removeDominated(x, y);
	pos[x] = y;
	return pos.size();
}

int main() {
	int t_c,n;
	int x, y;
	int total = 0;
	cin >> t_c;
	while (t_c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			total += count(x, y);
		}
		cout << total;
		total = 0;
		pos.clear();
	}
	cin >> total;
	return 0;
}