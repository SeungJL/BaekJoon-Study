#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	queue <int> q;
	queue <int> q_L;
	queue <int> q_R;
	vector <int> V;
	string str;
	int x;
	string str_2; // string은 어차피 자동으로 초기화가 된다.
	for (int i = 0; i < 27; i++) {
		q.push(i + 1);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		V.clear();
		for (int j = 0; j < 27; j++) {
			if (j < 13) {
				q_L.push(q.front());
				q.pop();
			}
			else {
				q_R.push(q.front());
				q.pop();
			}
		}
		if (i == 0) { cin.ignore(); }

		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ') {
				str_2 += str[i];
			}
			else {
				V.push_back(stoi(str_2));
				str_2 = "";
			}
			if (i == str.size() - 1) {
				V.push_back(stoi(str_2));
				str_2 = "";
			}
		}

		for (int i = 0; i < V.size(); i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < V[i]; j++) {
					q.push(q_R.front());
					q_R.pop();
				}
			}
			else {
				for (int j = 0; j < V[i]; j++) {
					q.push(q_L.front());
					q_L.pop();
				}

			}
		}
	}
	int cnt = 1;
	int k = q.size();
	for (int i = 0; i < k; i++) {
		if (q.front() == 1) {
			cout << cnt;
			return 0;
		}
		else {
			q.pop();
			cnt++;
		}
	}
}
