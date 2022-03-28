#include <iostream>
#include <string>

using namespace std;

int main() {
	long long N;
	cin >> N;
	string str;
	cin >> str;
	long long result = 0, C_count = 0, CO_count = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'C') 
			C_count++;
		else if (str[i] == 'O') {
			CO_count += C_count;
		}
		else if (str[i] == 'W') {
			result += CO_count;
		}
	}
	cout << result << endl;

	return 0;
}