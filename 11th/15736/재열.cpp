#include <iostream>

using namespace std;

int main() {
	unsigned long long N;
	int count = 0;
	cin >> N;

	for (int i = 1; i * i <= N; i++) 
		count++;
	
	cout << count << endl;

	return 0;
}