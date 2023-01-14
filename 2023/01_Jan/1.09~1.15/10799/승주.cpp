#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int temp = 0;
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				ans += temp;
				i++;
			}
			else {
				temp++;
			}
		}
		else {
			ans += 1;
			temp--;
		}
	}
	cout << ans;
}