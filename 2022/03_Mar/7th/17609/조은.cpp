#include <iostream>
#include <string>
using namespace std;

int checkStr(string str, int stat) {
	int len = str.size();
	int status = stat; // 기본 0, 회문 아니면 1, 회문도 유사회문도 아니면 X

	for(int i=0; i!=len/2; i++) {
		if(str[i] != str[len-i-1]) {
			if(status == 0) { // 회문에 어긋나는 경우가 처음 발견된 경우
				status = 1;

				/* 문제가 되는 문자 하나 제거 후, checkStr(str, 1) */
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
			else return 2; // 회문에 어긋나는 경우가 또 발견되면 유사회문도 아님
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