#include <iostream>
#include <string>

using namespace std;
int arr[4001][4001] = {};
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int Max = 0;
	for (int i = 1; i <= str1.size(); i++) { //str1의 한글자 한글자를 str2에 비교한다.
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				if (arr[i][j] > Max) {
					Max = arr[i][j];
				}
			}
		}
	}
	cout << Max;
}