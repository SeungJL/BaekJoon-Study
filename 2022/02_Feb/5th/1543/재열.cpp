#include <iostream>
#include <string>

using namespace std;

int main() {
	string str, search;
	getline(cin, str);
	getline(cin, search);

	int len = search.length();
	int count = 0;
	int index = 0;
	if (len > str.length()) {
		cout << 0 << endl;
		return 0;
	}
	while (index <= str.length() - len) {
		if (str.substr(index, len) == search) {
			count++;
			index += len;
		}
		else {
			index++;
		}
	}
	
	cout << count << endl;
	return 0;
}