#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a = 3, b = 3; // a는 세로 크기, b는 가로 크기
int r, c, k;

bool cmp(pair<int, int> P1, pair<int, int>P2) {
	if (P1.second < P2.second) {
		return true;
	}
	else if (P1.second == P2.second) {
		if (P1.first < P2.first) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

void Operation(vector<int>& V) {
	int max_T = 0;
	vector <int> Temp_V2(101, 0);
	vector <pair<int, int>> Temp_V;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] > max_T) { max_T = V[i]; }
		Temp_V2[V[i]]++;
	}
	for (int i = 0; i < Temp_V2.size(); i++) {
		if (Temp_V2[i] != 0) {
			Temp_V.push_back(make_pair(i, Temp_V2[i]));
		}
		if (i == max_T) { break; }
	}
	sort(Temp_V.begin(), Temp_V.end(), cmp);
	V.clear();
	for (int i = 0; i < Temp_V.size(); i++) {
		if (V.size() == 100) {
			break;
		}
		V.push_back(Temp_V[i].first);
		V.push_back(Temp_V[i].second);
	}
}


int main() {

	vector <int> V;
	int arr[101][101] = {};
	int cnt = 0;
	int b_temp = 3, a_temp = 3;

	cin >> r >> c >> k;
	r--; c--;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		a = a_temp;
		b = b_temp;
		if (arr[r][c] == k) {
			cout << cnt;
			return 0;
		}
		if (cnt == 100) {
			cout << -1;
			return 0;
		}
		cnt++;
		if (a >= b) {
			for (int i = 0; i < a; i++) {
				V.clear();
				for (int j = 0; j < b; j++) {
					V.push_back(arr[i][j]);
				}
				Operation(V);
				if (V.size() > b_temp) {
					b_temp = V.size();
				}
				for (int j = 0; j < V.size(); j++) {
					arr[i][j] = V[j];
				}
			}
		}
		else {
			for (int i = 0; i < b; i++) {
				V.clear();
				for (int j = 0; j < a; j++) {
					V.push_back(arr[j][i]);
				}
				Operation(V);
				if (V.size() > a_temp) {
					a_temp = V.size();
				}
				for (int j = 0; j < V.size(); j++) {
					arr[j][i] = V[j];
				}
			}
		}
	}

}