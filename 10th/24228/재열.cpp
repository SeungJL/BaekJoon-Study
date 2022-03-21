#include <iostream>

using namespace std;

int main() {
	unsigned long long int N, R;
	cin >> N >> R;

	unsigned long long count = N;		
	unsigned long long pair = 0;	
	
	count++;
	pair++;

	while (pair < R) {
		count += 2;
		pair ++;
	}

	cout << count << endl;
	return 0;
}