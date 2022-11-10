#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string Floor[10];
bool check[10];
vector <string> V;
int n, k;


void Convi(int a, int b, int c, string s) { //a는 첫번째 집은 카드의 위치 ,  b는 현재 집은 카드의 위치, c는 집은 카드 개수 

	if (c == 0) {
		s = Floor[a];
		check[a] = 0;
		c = 1;
	}
	else if (c == k) {
		V.push_back(s);

		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == 1) {
			check[i] = 0;
			Convi(a, i, c + 1, s + Floor[i]);
			check[i] = 1;


		}
	}


}

int main() {
	string str;
	int cnt = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> str;
		Floor[i] = str;
		check[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		Convi(i, 0, 0, "");
		for (int j = 0; j < n; j++) {
			check[j] = 1;
		}

	}

	sort(V.begin(), V.end());
	if (V.size() == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 0; i <= V.size() - 2; i++) {
		if (V[i] != V[i + 1]) {
			cnt++;
		}
	}
	cout << cnt + 1;


}