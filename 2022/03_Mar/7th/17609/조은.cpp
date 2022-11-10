#include <iostream>
#include <string>
using namespace std;

int checkStr(string str, int stat) {
	int len = str.size();
	int status = stat; // �⺻ 0, ȸ�� �ƴϸ� 1, ȸ���� ����ȸ���� �ƴϸ� X

	for(int i=0; i!=len/2; i++) {
		if(str[i] != str[len-i-1]) {
			if(status == 0) { // ȸ���� ��߳��� ��찡 ó�� �߰ߵ� ���
				status = 1;

				/* ������ �Ǵ� ���� �ϳ� ���� ��, checkStr(str, 1) */
				char tmp = str[i];
				str.erase(i, 1);
				//cout << str << endl;
				if(checkStr(str, 1) == 1) return 1;
				else {
					str.insert(i, 1, tmp);
					str.erase(len-i-1, 1);
					//cout << str << endl;
					return checkStr(str, 1);
				}
			}
			else return 2; // ȸ���� ��߳��� ��찡 �� �߰ߵǸ� ����ȸ���� �ƴ�
		}
	}
	if(status) return 1;
	else return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	string str;
	while(T--) {
		cin >> str;
		int res = checkStr(str, 0);
		cout << res << '\n';
	}

	return 0;
}