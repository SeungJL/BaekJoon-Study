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
		if (flag) { // �ܾ ã������
			cnt++;
			i += len_word; // �ܾ� ���� ��ŭ ����
		}
		else { // �� ã������
			i++;
		}
	}

	cout << cnt;

	return 0;
}