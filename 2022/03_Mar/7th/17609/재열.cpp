#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		int status = 0;		//현재 스킵한 횟수
		int n1 = 0;
		int n2 = s.length()-1;
		int signal = false;
		while (n1 <= s.length() / 2) {	
			if (n1 == s.length() / 2 && !signal) break;

			if (s[n1] != s[n2]) {
				status++;
				if (status == 1) {
					if (s[n1+1] == s[n2] && s[n1] == s[n2-1]) {
						int x1 = n1 + 2;
						int x2 = n2 - 1;
						bool flagX = false;
						while (x1 <= s.length() / 2) {
							if (s[x1] != s[x2]) {
								flagX = true;
								break;
							}
							x1++; x2--;
						}
						int y1 = n1 + 1;
						int y2 = n2 - 2;
						bool flagY = false;
						while (y1 < s.length() / 2) {
							if (s[y1] != s[y2]) {
								flagY = true;
								break;
							}
							y1++; y2--;
						}
						if (flagX && flagY) status = 2;
						else status = 1;
						break;
					}
					else if (s[n1 + 1] == s[n2]) {
						signal = true;		//n1이 s.length() / 2 일때도 탐색해야 함.
						n1 += 2;
						n2 -= 1;
						continue;
					}
					else if (s[n1] == s[n2 - 1]) {
						n1 += 1;
						n2 -= 2;
						continue;
					}
					else {
						status++;		//2가 됨.
						break;
					}
				}
				if (status >= 2) 
					break;
			}
			else {
				n1++;
				n2--;
			}
		}

		cout << status << endl;
	}

	return 0;
}