#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int cache[101][101];
//���ϰ� ���ڿ�
string W, S;
vector<string> text;
vector<string> ret;

//���ϵ�ī�� ���� W[w...]�� ���ڿ� S[s...]�� �����Ǵ��� ���θ� ��ȯ�Ѵ�. O(n^3)
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	//W[w]�� S[s]�� ���糪����
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		w++; s++;
	}

	//�� �̻� �����Ҽ� ������ �� while���� ���������� Ȯ��
	// ���� ���� �����Ͽ� ���� ��� : ���ڿ��� ������� ����
	if (w == W.size())
		return ret = (s == S.size());

	// *�� ������ ���� ��� : *�� �� ���ڸ� ���ؾ� �ϴ��� �𸣹Ƿ� ���ȣ���Ͽ� Ȯ��
	if (W[w] == '*')
		for (int skip = 0; s + skip <= S.size(); skip++)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;

	//�� �ܿ� ����.
	return ret = 0;

}

void calWild(int n, string wild) {
	vector<string> res;
	W = wild;
	for (int i = 0; i<n; i++) {
		for (int x = 0; x < 101; x++) {
			for (int y = 0; y < 101; y++)
				cache[x][y] = -1;
		}
		S = text[i];
		if (matchMemoized(0, 0)) {
			res.push_back(text[i]);
		}
	}

	sort(res.begin(), res.end());

	ret.insert(ret.end(), res.begin(), res.end());
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		string wild;
		int n;
		cin >> wild >> n;
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			text.push_back(temp);
		}
		calWild(n, wild);
		text.clear();
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}
	cin >> C;
}
