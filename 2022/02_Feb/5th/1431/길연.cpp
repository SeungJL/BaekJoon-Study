// 백준 1431번 시리얼 번호

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


bool cmp(string a, string b) {

	// 1번 조건. 길이가 다르면  짧은 것이 먼저 옴
	if (a.length() < b.length())
		return a.size() < b.size();

	// 2번 조건. 길이가 같다면 모든 자리수의 합 비교
	else if (a.length() == b.length()) {

		int aSum = 0;
		int bSum = 0;

		for (int i = 0; i <= a.length(); i++) {
			if ('0' <= a[i] && a[i] <= '9')
				aSum += (a[i] - '0');
		}
		for (int i = 0; i <= b.length(); i++) {
			if ('0' <= b[i] && b[i] <= '9')
				bSum += (b[i] - '0');
		}

		if (aSum == bSum) {
			if (a.compare(b) < 0)
				return true;
			return false;
		}
		else
			return aSum < bSum;
	}

	// 1번 조건. 길이가 다르면  짧은 것이 먼저 옴
	else
		return false;
}


int main() {

	int num = 0;
	cin >> num;
	vector<string> str(num, "");
	
	for (int i = 0; i < num; i++)
		cin >> str[i];

	sort(str.begin(), str.end(), cmp);

	for (int i = 0; i<str.size(); i++)
		cout << str[i] << endl;

	
	return 0;
}
