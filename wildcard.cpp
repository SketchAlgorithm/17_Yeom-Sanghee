#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int cache[101][101];
//패턴과 문자열
string W, S;
vector<string> text;
vector<string> ret;

//와일드카드 패턴 W[w...]가 문자열 S[s...]에 대응되는지 여부를 반환한다. O(n^3)
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	//W[w]와 S[s]를 맞춰나간다
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		w++; s++;
	}

	//더 이상 대응할수 없으면 왜 while문이 끝났는지를 확인
	// 패턴 끝에 도달하여 끝난 경우 : 문자열도 끝났어야 성공
	if (w == W.size())
		return ret = (s == S.size());

	// *를 만나서 끝난 경우 : *에 몇 글자를 더해야 하는지 모르므로 재귀호출하여 확인
	if (W[w] == '*')
		for (int skip = 0; s + skip <= S.size(); skip++)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;

	//그 외엔 실패.
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
