#include<vector>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;
//abcdefghijklmnopqrstuvwxyz
//A = 65

struct dic {
	string word;
	int priority;

	dic(string _word, int _priority) {
		word = _word;
		priority = _priority;
	}
};

bool cmp(const dic a, const dic b) {
	if (a.priority > b.priority)
		return true;
	else if (a.priority == b.priority)
		return a.word < b.word;
	else
		return false;
}

vector<dic> alp[27];
string typing[20002];

int calc();
int M;

int main() {
	int C, N;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		cin >> M;
		for (int j = 0; j < N; j++) {
			string word;
			int priority;
			cin >> word >> priority;

			alp[word.at(0) - 65].push_back(dic(word, priority));
		}

		for (int j = 0; j < M; j++) {
			cin >> typing[j];
		}

		for (int j = 0; j < 26; j++) {
			sort(alp[j].begin(), alp[j].end(), cmp);
		}

		cout << calc();
		for (int j = 0; j < 27; j++) {
			alp[j].clear();
		}

	}
	return 0;

}


int calc() {
	int count = 0;
	for (int i = 0; i < M; i++) {
		string word = typing[i];
		int index = typing[i].at(0) - 65; //첫 알파벳
		int t_index = 0;//몇번째 글자를 보고 있는지
		bool check = false;
		/*n번째 글자를 보고 있다.
		  n번째 글자까지 같고 그 첫번째 단어가 같다면 count
		  다르면 더 봐야 함*/
		if (alp[index].size() == 0)
			t_index = word.length();
		for (int k = 0; k < alp[index].size(); k++) {
			if ((alp[index].at(k).word.at(t_index)) == word.at(t_index)) {//해당 보는 글자가 같으면
				if (!alp[index].at(k).word.compare(word)) { //단어 전체가 같으면
					count += 2;
					break;
				}
				else {
					int temp = t_index;
					while (k + 1 < alp[index].size()) { //thanks와 the
						if (alp[index].at(k).word.at(t_index + 1) == alp[index].at(k + 1).word.at(t_index + 1)) {
							t_index = temp + 1;
						}
						else
							break;
					}
					t_index++;
				}
			}
			if (k == alp[index].size() - 1) { //끝까지 봤는데 그게 나올수도
				t_index = word.length();
			}
		}
		count += t_index;
	}
	count += (M-1);
	return count;
}