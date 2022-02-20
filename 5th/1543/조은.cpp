#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	string s, word;
	getline(cin, s);
	getline(cin, word);
	int len_s = s.size();
	int len_word = word.size();

	int cnt = 0;
	for (int i = 0; i <= len_s - len_word; ) {
		bool flag = true;
		for (int j = i; j < i + len_word; j++) {
			if (s[j] != word[j - i]) {
				flag = false;
				break;
			}
		}
		if (flag) { // 단어를 찾았으면
			cnt++;
			i += len_word; // 단어 길이 만큼 점프
		}
		else { // 못 찾았으면
			i++;
		}
	}

	cout << cnt;

	return 0;
}