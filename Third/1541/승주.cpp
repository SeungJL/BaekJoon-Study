#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;
vector <int> V;
int Min = 10000000;
int check2(int index, int p, int n) {
	int sum3 = 0; // �� ��ȣ ������ ������ ��
	for (int i = index + 1; i < V.size(); i++) {
		sum3 += V[i];
	}
	return n - p + sum3;
}
void check(int index, int n) {
	int p = -V[index]; // ��ȣ ������ ������
	int x;
	for (int i = index + 1; i < V.size(); i++) {
		p += V[i];
		x = check2(i, p, n);
		if (x < Min) {
			Min = x;
		}
	}
	return;
}



int main() {
	string str;

	cin >> str;
	string s;
	int h = 0;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '-' || str[i] == '+' || i == str.size()) {
			if (h == 0) { V.push_back(stoi(s)); }
			else { V.push_back(-stoi(s)); }
			if (i == str.size()) {
				break;
			}
			if (str[i] == '+') { h = 0; }
			else { h = 1; }
			s = "";
		}
		else {
			s += str[i];
		}
	}
	int sum = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] <= 0) {
			check(i, sum);// i�� -�� ���� ���� index, sum�� -�� ������ ������ ���ڵ��� ��
			sum += V[i]; //ä���� ���� �ʴ� ��� �׳� pass�ϰ� ����
		}
		else {
			sum += V[i];
		}
	}
	if (sum < Min) {
		Min = sum;
	}
	cout << Min;
}