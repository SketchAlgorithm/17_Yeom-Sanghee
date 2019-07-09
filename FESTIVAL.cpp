#include <iostream>

using namespace std;

int value[1002] = { 0, }; //�뿩��� ����
double ret[102] = { 0, }; //�ּ� ��� ����

double calc(int n, int l); // �ּ� ��� ��� ���ϴ� �Լ�

int main() {
	int c; //���̽� ��
	int n; //�뿩�� �� �ִ� ��
	int l; //������ �� ��
	//�Է�
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> l;
		for (int j = 0; j < n; j++)
			cin >> value[j];
		ret[i] = calc(n, l);
	}

	for (int i = 0; i < c; i++) {
		printf("%.12f\n", ret[i]);
	}

	return 0;
}

double calc(int n, int l) { // �ּ� ��� ��� ���ϴ� �Լ�
	double ret = 0;
	int temp = 0;

	for (int j = n-l; j <n ; j++) { //���� ������ ��츸 ���� ���
		temp += value[j];
	}

	ret = (double)temp / l;

	for (int i = 0; i < n - l; i++) {
		temp = 0;

		for (int j = 0; j < l; j++) { //ó�� �ʿ��� ����ŭ ���
			temp += value[i + j];
		}

		if ((double)temp / l < ret)
			ret = (double)temp / l;


		for (int j = i + l; j < n; j++) { //�ϳ��� �߰��ϸ� ���
			temp += value[j];
			if ((double)temp/ (j-i+1) < ret)
				ret = (double)temp/ (j - i + 1);
		}
	}
	return ret;
}