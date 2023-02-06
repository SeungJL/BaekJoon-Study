#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string longToStr(int cnt, bool isMax) {
	string temp = "1";
	if (isMax) temp = "5";
	for (int i = 0; i < cnt; i++) {
		temp += '0';
	}
	if (!isMax) temp += '5';
	return temp;
}

int main() {
	string MK_Num;
	string ans;
	string Max_ans;
	cin >> MK_Num;
	long long m_temp = 0;
	for (int i = 0; i < MK_Num.length(); i++) {

		if (MK_Num[i] == 'K') {
			if (m_temp == 0) { ans += '5'; Max_ans += '5'; continue; }
			ans += longToStr(m_temp - 1, false);
			Max_ans += longToStr(m_temp, true);
			m_temp = 0;
		}
		else if (i == MK_Num.length() - 1) {
			ans += '1';
			Max_ans += '1';
			for (int j = 0; j < m_temp; j++) {
				ans += "0";
				Max_ans += '1';

			}
		}
		else {
			m_temp++;
		}
	}
	cout << Max_ans << endl << ans;
}