#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector <char> V2(11);
vector <char> V;
queue<int>q;
int a, b;
int list[11] = { 0 };
int N;
int Max = -1000000000;
int Min = 1000000000;

void SJ(vector<char>V2, int start, int end) {
	if (start == end) {
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				a = list[i];
				q.push(a);
			}
			else {
				a = list[i];
				q.pop();
				switch (V2[i - 1]) {
				case '+':
					q.push(b + a);
					break;
				case '-':
					q.push(b - a);
					break;
				case '*':
					q.push(b * a);
					break;
				case '/':
					q.push(b / a);
					break;
				}

			}
			b = q.front();
		}
		if (b < Min) {
			Min = b;
		}
		if (b > Max) {
			Max = b;
		}
		q.pop();
	}

	else {
		for (int i = start; i <= end; i++) {
			swap(V2[start], V2[i]);
			SJ(V2, start + 1, end);
			swap(V2[start], V2[i]);
		}
	}
}


int main() {

	int k;
	char c;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> k;
		switch (i) {
		case 0:
			c = '+';
			break;
		case 1:
			c = '-';
			break;
		case 2:
			c = '*';
			break;
		case 3:
			c = '/';
			break;
		}
		for (int j = 0; j < k; j++) {
			V.push_back(c);
		}
	}
	sort(V.begin(), V.end());

	SJ(V, 0, N - 2);

	cout << Max << endl << Min;
}