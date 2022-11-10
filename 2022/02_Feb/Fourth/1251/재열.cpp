#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<string> vec;

	//i, j, k는 세 단어로 나눴을 때 각 단어의 길이
	for (int i = 1; i <= str.length()-2; i++) {
		for (int j = 1; j <= str.length()-i-1; j++) {
			//i, j가 정해지면 k도 정해짐
			int k = str.length() - i - j;

			string sub1 = str.substr(0, i);
			string sub2 = str.substr(i, j);
			string sub3 = str.substr(i+j, k);

			reverse(sub1.begin(), sub1.end());
			reverse(sub2.begin(), sub2.end());
			reverse(sub3.begin(), sub3.end());

			string newStr = sub1;
			newStr += sub2;
			newStr += sub3;

			vec.push_back(newStr);
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec[0] << endl;

	return 0;
}