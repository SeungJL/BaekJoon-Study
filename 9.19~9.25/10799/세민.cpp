#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);

	string str;
	cin >> str;

	int cnt = 0, len = str.length();
	for (int i = 0; i < len; ++i) {
		if (str[i] == '(') st.push(str[i]);	// ���� ��ȣ�� ��� ���ÿ� push
		else {	// ')' �ݴ� ��ȣ�� ���
			st.pop();
			if (str[i - 1] == '(') {	//�������� ���
				cnt += st.size();
			}
			else {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}