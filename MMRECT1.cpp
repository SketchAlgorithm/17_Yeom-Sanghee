#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
};

int n;
int r_min[22] = { 0, };
int r_max[22] = { 0, };
struct Point p[52];

void calc(int index, int c_index);
bool cmp(const Point&p1, const Point&p2);

int main() {
	//�Է�
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> p[j].x >> p[j].y;
		}
		sort(p, p + n, cmp);
		r_min[i] = 1000000;
		r_max[i] = -1;
		calc(0, i);
		
	}

	for (int i = 0; i < c; i++)
		cout << r_min[i] << " " << r_max[i] << endl;
	
	return 0;
}

void calc(int index, int c_index) {//������ġ
	//���� index�� 0�̶��
	//index
	if (index + 3 >= n) return;

	int temp = index + 1;

	while (1) {
		//2��° ��ǥ ���ϱ�
		if (p[index].x == p[temp].x) {
			int d = p[temp].y - p[index].y; // ����
			for (int i = temp + 1; i < n-1; i++) {
				//3��° ��ǥ ���ϱ�
				if (p[i].x == p[index].x + d) {
					for (int j = i+1; j < n; j++) {
						//4��° ��ǥ ���ϱ�
						if (p[i].x == p[j].x) {
							if (p[j].y - p[i].y == d) {
								//�ִ� �ּ� ��
								r_min[c_index] > d ? r_min[c_index] = d : 0;
								r_max[c_index] < d ? r_max[c_index] = d : 0;
							}
						}
						else
						{
							break;
							//������ -> �����ϱ�
						}
					}
				}
				else if (p[i].x > p[index].x + d) {
					break;
				}
			}
			temp++;
		}
		else  break;
	}
	return calc(index + 1, c_index);

}

bool cmp(const Point&p1, const Point&p2) {
	if (p1.x < p2.x)
		return true;
	else if (p1.x == p2.x)
		return p1.y < p2.y;
	else
		return false;
}