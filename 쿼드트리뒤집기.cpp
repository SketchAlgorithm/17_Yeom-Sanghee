#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator &itr) {

	char head = *(itr);

	++itr;

	if (head == 'w' || head == 'b') return string(1,head);

	string lefttop = reverse(itr);
	string righttop = reverse(itr);
	string leftbottom = reverse(itr);
	string rightbottom = reverse(itr);

	return "x" + leftbottom + rightbottom + lefttop + righttop;
}

int main() {

	int t = 0;
	string s;
	cin >> t;

	while (t--) {
		cin >> s;
		string::iterator itr = s.begin();
		cout << reverse(itr) << "\n";
	}

	cin >> t;
}