// 백준 17609번 회문
// 2022년 03월 06일

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <string> v;

// 회문 : 0, 유사회문 : 1, 일반문 : 2
int Palindrome(int left, int right, bool del, string str) {

	while (left < right) {   // 가운데에서 만나기 전까지 반복
		if (str[left] != str[right]) {
			if (del == 0) {// 한 번도 삭제한 적 없다면
				if (Palindrome(left + 1, right, 1, str) == 0 || Palindrome(left, right - 1, 1, str) == 0)
					return 1;   // 왼쪽이나 오른쪽에서 삭제한 거 둘 중하나가 똑같으면 유사회문
				else return 2;  // 삭제해도 안같으면 일반문
			}
			else return 2; // 삭제한 적 있다면
		}
		else {  // 같다면 
			left++;
			right--;
		}
	}
	return 0;
}

int main() {
	int t;
	int ans;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < t; i++) {
		string str = v[i];
		int ans = Palindrome(0, str.length() - 1, 0, str);
		cout << ans << endl;
	}

	return 0;
}
