#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int getNumAdd(string& s) {
	int sum = 0;
	for (auto c : s) {
		if (c - '0' >= 0 && c - '0' <= 9) {
			sum += (c - '0');
		}
	}
	return sum;
}

bool compare(string& s1, string& s2) {
	if (s1.length() == s2.length()) {
		int a1 = getNumAdd(s1);
		int a2 = getNumAdd(s2);
		if (a1 == a2) {
			return s1 < s2;
		}
		else {
			return a1 < a2;
		}
	}
	else {
		return s1.length() < s2.length();
	}
}


int main() {
	int N;
	cin >> N;
	vector<string> guitars(N);

	for (int i = 0; i < N; i++) {
		cin >> guitars[i];
	}

	sort(guitars.begin(), guitars.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << guitars[i] << endl;
	}

	return 0;
}

